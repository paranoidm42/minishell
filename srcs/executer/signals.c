/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:03:18 by bcopoglu          #+#    #+#             */
/*   Updated: 2024/01/25 23:15:34 by ccur             ###   ########.fr       */
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
