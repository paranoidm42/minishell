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
	if (s[i] == c && c != ' ' && s[i + 1] > 32 ) // duruma göre buraya ardışık tırnaklarda kontrol eklenebilir
		while (s[i] != ' ' && s[i])
		{
			i++;
			size++;
		}

	return (size);
}
int quote_check(const char *input)
{
    int xsingle = 0;
    int ydouble = 0;
    while (*input)
    {
        if (*input == '\'' && !ydouble)
            xsingle = (xsingle + 1) % 2;
        else if (*input == '"' && !xsingle)
            ydouble = (ydouble + 1) % 2;

        input++;
    }
    if (ydouble != 0 || xsingle != 0)
        return -1;
    return 0;
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
		}
		else
		{
			i++;
			sub[j] = ft_substr(s, i, size_word(s, c, i));
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
	if (!command || quote_check(data->cmd) == -1)
		return ;
	i = 0;
	data->lex = malloc(sizeof(t_lex));
	while (command[i])
	{
		data->lex->content = command[i];

		i++;
	}
}
