/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:03:18 by bcopoglu          #+#    #+#             */
/*   Updated: 2024/01/25 21:37:20 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <unistd.h>
#include <sys/errno.h>
#include <sys/param.h>

bool	ft_set_oldpwd(t_init *process, t_env *env, char *str, size_t i)
{
	char	*temp;

	temp = ft_strjoin("OLDPWD=", str);
	if (!temp)
		return (ft_throw_error(process, ENOMEM), false);
	free(env->new_env[i]);
	env->new_env[i] = temp;
	return (true);
}

bool	ft_set_pwd(t_init *process, t_env *env, char *buffer, size_t i)
{
	char	*temp;

	if (!getcwd(buffer, MAXPATHLEN))
		return (ft_throw_error(process, errno), true);
	temp = ft_strjoin("PWD=", buffer);
	if (!temp)
		return (ft_throw_error(process, ENOMEM), false);
	free(env->new_env[i]);
	env->new_env[i] = temp;
	return (true);
}
