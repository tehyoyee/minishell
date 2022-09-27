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
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handler_sigterm(int signum)
{
	printf("exit\n");
	exit(0);
}

int	main(int argc, char *argv[], char *envp[])
{
	signal(SIGINT, handler_sigint);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, handler_sigterm);
	if (argc != 1)
		return (-1);
	while (1)
	{
		set_terminal(envp);
	}
}