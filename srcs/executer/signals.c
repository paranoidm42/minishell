/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:03:18 by bcopoglu          #+#    #+#             */
/*   Updated: 2024/01/30 09:53:10 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <termios.h>
#include <signal.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <sys/errno.h>
#include <sys/param.h>

static void	ft_interactive_handler(int32_t signum)
{
	if (signum == SIGINT)
	{
		g_signal = SIGINT;
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	if (signum == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	ft_noninteractive_handler(int32_t signum)
{
	if (signum == SIGINT)
	{
		g_signal = SIGINT;
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_redisplay();
	}
	if (signum == SIGQUIT)
		ft_putendl_fd("Quit (core dumped)", STDIN_FILENO);
}

bool	ft_setup_noninteractive(t_init *process)
{
	struct termios		term;

	if (tcgetattr(0, &term) == -1)
	{
		ft_throw_error(process, errno);
		return (false);
	}
	term.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, 0, &term) == -1 || \
		signal(SIGINT, ft_noninteractive_handler) == SIG_ERR || \
		signal(SIGQUIT, ft_noninteractive_handler) == SIG_ERR)
	{
		ft_throw_error(process, errno);
		return (false);
	}
	if (g_signal == SIGINT)
	{
		process->errorcode = 130;
		g_signal = 0;
	}
	return (true);
}

bool	ft_setup_interactive(t_init *process)
{
	struct termios		term;

	if (tcgetattr(0, &term) == -1)
	{
		ft_throw_error(process, errno);
		return (false);
	}
	term.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, 0, &term) == -1 || \
		signal(SIGINT, ft_interactive_handler) == SIG_ERR || \
		signal(SIGQUIT, ft_interactive_handler) == SIG_ERR)
	{
		ft_throw_error(process, errno);
		return (false);
	}
	return (true);
}

int	cmd_control(t_cmd *cmd)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (cmd->arg[j])
	{
		i = 0;
		while (cmd->arg[j][i])
		{
			if (cmd->arg[j][0] == '-' || cmd->arg[j][0] == '+')
				i++;
			if (!ft_isdigit(cmd->arg[j][i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
