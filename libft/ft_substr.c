/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 22:26:11 by ccur              #+#    #+#             */
/*   Updated: 2023/12/22 01:56:29 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;

	slen = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= slen)
	{
		str = (char *)malloc(1 * sizeof(char));
		if (!str)
			return (NULL);
		*str = '\0';
	}
	else
	{
		if (slen - start < len)
			len = slen - start;
		str = (char *)malloc((len + 1) * sizeof(char));
		if (!str)
			return (NULL);
		ft_strlcpy(str, (s + start), len + 1);
	}
	return (str);
}
