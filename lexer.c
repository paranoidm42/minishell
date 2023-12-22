#include "minishell.h"

int	count_word(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] <= 32)
			i++;
		if (IS_QUOTE(s[i]))
		{
			c = s[i];
			i++;
			while (s[i] != c)
				i++;
			i++;
			count++;
		}
		if (s[i] && s[i] > 32)
		{
			while (s[i] && s[i] > 32)
				i++;
			count++;
		}
	}
	return (count);
}
int	size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	if (s[i] == c && c != ' ')
    {
		while (s[i] != ' ' && s[i])
		{
			i++;
			size++;
		}
        return (size - 1);
    }
	return (size);
}
int	quote_check(char const *s, int i, char c)
{
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		return (1);
	return (0);
}

char	**lexer_split(char const *s, int i, int j)
{
	int		n;
	char	c;
	char	**sub;

	n = count_word(s, '"'); // ikinci argüman 25 satırdan kaçınmak için
	sub = (char **)malloc(sizeof(char *) * (n + 1));
	if (!sub)
		return (0);
	while (++j < n)
	{
		while (s[i] == ' ')
			i++;
		c = s[i];
		if (!IS_QUOTE(c))
		{
			sub[j] = ft_substr(s, i, size_word(s, ' ', i));
			i += size_word(s, ' ', i);
            if (quote_check(sub[j], 0, '"'))
				return NULL;
		}
		else
		{
			i++;
            if (!quote_check(s, i, c))
				return NULL;
			sub[j] = ft_substr(s, i, size_word(s, c, i));
            if (quote_check(sub[j], 0, c))
				return NULL;
			i += size_word(s, c, i);
		}
		i++;
	}
	sub[j] = 0;
	return (sub);
}

void	lexer_main(t_data *data)
{
	char	**command;
	int		i;

	command = lexer_split(data->cmd, 0, -1);
		// ikinci ve üçüncü argüman 25 satırdan kaçınmak için
	if (!command)
		return ;
	i = 0;
	while (command[i])
	{
		printf("%s|\n", command[i]);
		i++;
	}
}
