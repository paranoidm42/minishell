/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:03:18 by bcopoglu          #+#    #+#             */
/*   Updated: 2024/01/25 21:35:07 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_find_unset_arg(char **env, char *arg, size_t len)
{
	char	*temp;
	size_t	j;

	j = 0;
	while (env[j])
	{
		if (!ft_cmpname(arg, env[j], len) && \
			(env[j][len] == '=' || !env[j][len]))
		{
			temp = env[j];
			while (env[j])
			{
				env[j] = env[j + 1];
				j++;
			}
			free(temp);
			temp = NULL;
			env[j] = NULL;
			break ;
		}
		j++;
	}
}

void	ft_unset_builtin(t_init *process, t_cmd *cmd)
{
	size_t	i;
	size_t	len;
	char	**arg;
	char	**env;

	i = 1;
	arg = cmd->arg;
	env = cmd->env->new_env;
	process->errorcode = 0;
	if (!arg[i])
		return ;
	while (arg[i])
	{
		len = ft_strlen(arg[i]);
		ft_find_unset_arg(env, arg[i], len);
		i++;
	}
}
