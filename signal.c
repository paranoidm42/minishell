#include "minishell.h"

void	sig_int(int sig)
{
	(void)sig;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_replace_line("", 0);
	rl_on_new_line();
}

void	ft_signal(int flag)
{
	if (flag == 1)
	{
		signal(SIGINT, sig_int);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (flag == 3)
		exit (0);
}

<<<<<<< HEAD
//ccura selamlar
//bedirhana selamlar
=======
//ccura selamlar
>>>>>>> ac3ac5f3614ea65a323b542a7f54613d4f7bfb99
