/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 03:01:58 by ccur              #+#    #+#             */
/*   Updated: 2024/01/30 11:00:17 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_quotes	quote_check(const char *str, size_t start)
{
	bool	in_single;
	bool	in_double;
	size_t	i;

	in_single = false;
	in_double = false;
	i = 0;
	while (str[i] != '\0' && i < start)
	{
		if (str[i] == '\'' && in_double == false)
			in_single = !in_single;
		if (str[i] == '\"' && in_single == false)
			in_double = !in_double;
		i++;
	}
	if (in_double == true)
		return (IN_DOUBLE);
	else if (in_single == true)
		return (IN_SINGLE);
	else
		return (NOT_QUOTED);
}

char	*find_end(char *str, char *beginning, size_t len)
{
	char	*end;
	size_t	i;

	i = 0;
	while (str[i] == beginning[i])
		i++;
	if (str[i] == '$' && ft_isdigit(str[i + 1]))
		i += 2;
	else
	{
		if (str[i] == '$')
			i++;
		while (str[i] != '\0')
		{
			if (ft_isalnum(str[i]) == 0 && str[i] != '_' && str[i] != '?')
				break ;
			i++;
		}
	}
	len = ft_strlen(&str[i]);
	if (i > 0 && str[i] == '$' && str[i - 1] == '$')
		end = ft_substr(str, i + 1, len);
	else
		end = ft_substr(str, i, len);
	return (end);
}

char	*find_middle(char *str, size_t i, size_t len)
{
	char	*middle;

	while (str[i] != '\0')
	{
		if (str[i] == '$' && ft_strchr(" ", str[i + 1]) == NULL)
		{
			if (str[i + 1] == '$')
			{
				len++;
				break ;
			}
			while (str[i + len] != '\0')
			{
				if (ft_isalnum(str[i + len]) == 0 && \
					ft_strchr("_?", str[i + len]) == NULL)
					break ;
				len++;
			}
			if (ft_isalnum(str[i + len]) == 0 && str[i + len] != '_')
				break ;
		}
		i++;
	}
	middle = ft_substr(str, i + 1, len - 1);
	return (middle);
}

char	*find_begin(char *str, bool in_heredoc)
{
	char	*beginning;
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$' && ft_strchr(" ", str[i + 1]) == NULL)
		{
			if (in_heredoc == false)
			{
				if (quote_check(str, i) != IN_SINGLE)
					break ;
			}
			else
				break ;
		}
		i++;
	}
	beginning = ft_substr(str, 0, i);
	return (beginning);
}

void	multi_free(char *begin, char *mid, char *end, char *temp)
{
	if (begin)
		free(begin);
	if (mid)
		free(mid);
	if (end)
		free(end);
	if (temp)
		free(temp);
}
