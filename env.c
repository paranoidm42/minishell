/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:03:46 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/12/21 16:05:03 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_envo  *env_list(char **environment)
{
    t_envo  *env;
    int     i = 0;

    while (env->next)
    {
        env->title = ft_split(environment[i], '=');
    }
}