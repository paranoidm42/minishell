/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:03:18 by bcopoglu          #+#    #+#             */
/*   Updated: 2024/01/25 21:37:30 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <sys/errno.h>

void	ft_free_pipes(t_init *process, size_t pipe_count)
{
	size_t	i;

	i = 0;
	while (i < pipe_count)
	{
		free(process->pipes[i]);
		process->pipes[i] = NULL;
		i++;
	}
	process->pipe_count = 0;
	if (process->pipes)
	{
		free(process->pipes);
		process->pipes = NULL;
	}
}

size_t	ft_count_pipes(t_list *lst)
{
	size_t	pipe_count;

	pipe_count = 0;
	while (lst->next)
	{
		pipe_count++;
		lst = lst->next;
	}
	return (pipe_count);
}

bool	ft_create_pipes(t_init *process, size_t pipe_count)
{
	size_t	i;

	i = 0;
	process->pipes = malloc(pipe_count * sizeof(int32_t *));
	if (!process->pipes)
		return (perror("minishell"), false);
	while (i < pipe_count)
	{
		process->pipes[i] = malloc(2 * sizeof(int32_t));
		if (!process->pipes[i] || pipe(process->pipes[i]) == -1)
		{
			perror("minishell");
			ft_free_pipes(process, i);
			return (false);
		}
		i++;
	}
	return (true);
}
