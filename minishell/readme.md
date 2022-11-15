My Minishell is public so you might actually read this.

This Minishell is beautiful, all Minishells are beautiful.

But it could be better.

Before you start, read the mans for all builtins and remember what is not asked for is not to do and what is undef is undef

If you have never implemented pipex do it, it will save you so much time and sweat.

Regarding the above mentioned tip, I chose not to do it, don't do like me, its stupid!

Remember to always check if things exist before you free them and that should be the case especially if you run it with env -i

I think for behaviour you should stick to bash and not posix

Also if you run it with valgring problems might appear for the ctrl /, why is to be determined but try to run bash with valgrind...

I used a singleton, it's not a global stucture but kind of is, the good thing is it's accepted by norminett

Because of the singleton you have a bunch of still reachables while you haven't exited the shell

For fd leaks i close most of them and leave 3 to 4 open, bash tends to leak fds anyway

Also make sure to call your own libft function and not standard ones, I might have forgotten one or two in there!

If you find a way to make my code segfault I would appreciate feedback.
