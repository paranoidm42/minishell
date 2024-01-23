/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:01:22 by ccur              #+#    #+#             */
/*   Updated: 2024/01/23 22:10:11 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	first;
	size_t	total;

	first = ft_strlen(s1) + 1;
	total = ft_strlen(s2) + first;
	new = (char *)malloc(total * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, first);
	ft_strlcat(new, s2, total);
	return (new);
}
