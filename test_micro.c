#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int	put_error( char *str, char *arg ) {
	
	write( 2, str, strlen( str ) );
	if ( arg )
		write( 2, arg, strlen( arg ) );
	write( 2, "\n", 1 );
	return ( 1 );
}

int execute( char **av, int i, int tmp_fd, char **env ) {
	av[i] = NULL;
	dup2( tmp_fd, STDIN_FILENO );
	close(tmp_fd);
	execve( av[0], av, env );
	return ( put_error( "error: cannot execute ", av[ 0 ] ) );
}

void cd( char **av, int i ) {

	if ( i != 2 )
		put_error( "error : cd: bad arguments", NULL );
	else if ( chdir( av[1]) )
		put_error( "error : cd: cannot change directory to ", av[ 1 ] );
}

int	main(int ac, char **av, char **env) {
	
	int	i = 0;
	int fd[ 2 ];
	int tmp_fd = dup( STDIN_FILENO );
	(void)ac;


	while (av[i] && av[i + 1]) {
		av = &av[i + 1];
		i = 0;
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		if (!strcmp(av[0], "cd"))
		{
			cd( av, i );
		}
		else if (i != 0 && (av[i] == NULL || strcmp(av[i], ";") == 0)) //exec in stdout
		{
			if ( fork() == 0)
			{
				if (execute(av, i, tmp_fd, env))
					return (1);
			}
			else
			{
				close(tmp_fd);
				while(waitpid(-1, NULL, WUNTRACED) != -1)
					;
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		else if(i != 0 && strcmp(av[i], "|") == 0) //pipe
		{
			pipe(fd);
			if ( fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if (execute(av, i, tmp_fd, env))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				tmp_fd = fd[0];
			}
		}
	}
	close(tmp_fd);
	return (0);
}