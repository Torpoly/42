#include "../../includes/minishell.h"

int	ft_csch(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

t_parsing	*parsing(t_lexer *lex)
{
	t_parsing	*par;

	if (!lex || !lex->str)
		return (NULL);
	par = init_par(lex);
	return (par);
}

t_parsing	*redir(t_parsing *par, t_lexer *lex, int i, char *s)
{
	if (par->fd_out != 1)
		printf("closed fd :%d\n", par->fd_out);
	if (lex->prev->koi == R_REDIR)
		par->fd_out = printf("fd out R :%d name %s\n", lex->prev->koi, lex->str);
	else if (lex->prev->koi == RR_REDIR)
		par->fd_out = printf("fd out RR:%d name %s\n", lex->prev->koi, lex->str);
	if (ft_csch(lex->str, ' '))
	{
		while (s[i] != ' ')
			i++;
		par->arg = ft_strjoin(par->arg, s + i);
	}
	return (par);
}

// t_parsing	*pipe(t_parsing *par)
// {

// }
