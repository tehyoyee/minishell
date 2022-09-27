#include "minishell.h"

int	set_terminal(char **envp)
{
	char	*cmd;

	cmd = readline("minishell$>");
	add_history(cmd);
	return (0);
}

void	handler_sigint(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	signal(SIGINT, handler_sigint);
	signal(SIGQUIT, SIG_IGN);
	if (argc != 1)
		return (-1);
	while (1)
	{
		set_terminal(envp);
	}
}