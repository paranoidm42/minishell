/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:03:22 by ccur              #+#    #+#             */
/*   Updated: 2023/07/13 16:32:21 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;
	size_t	totallen;
	char	*temp;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	totallen = len1 + len2;
	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc((totallen + 1) * sizeof(char));
	if (!result)
		return (NULL);
	temp = result;
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (result);
}
