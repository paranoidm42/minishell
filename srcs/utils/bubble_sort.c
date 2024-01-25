/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:02:25 by ccur              #+#    #+#             */
/*   Updated: 2024/01/25 23:09:39 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <sys/param.h>

static void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_bubble_sort(char **sortedenv, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < len - 1)
	{
		while (j < len - i - 1)
		{
			if (ft_strncmp(sortedenv[j], sortedenv[j + 1], MAXPATHLEN) > 0)
				ft_swap(&sortedenv[j], &sortedenv[j + 1]);
			j++;
		}
		j = 0;
		i++;
	}
}
