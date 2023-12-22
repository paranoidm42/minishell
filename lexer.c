#include "minishell.h"

int count_word(const char *s)
{
    int i;
    int count;
    char c;
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
// Burada tırnak sayısı kontrol edilecek

int	size_word(char const *s, char c, int i)
{
	int size;
	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}
char **lexer_split(char const *s)
{
    int i;
    int j;
    int n;
    char c;
    char **sub;
    n = count_word(s);
    sub = (char **)malloc(sizeof(char *) * (n + 1));
    if(!sub)
        return (0);
    j = -1;
    i = 0;
    while (++j < n)
    {
        while (s[i] == ' ')
            i++;
        c = s[i];
        if(!IS_QUOTE(c))
        {
            sub[j] = ft_substr(s,i,size_word(s,' ',i));
            i += size_word(s,' ',i);
        }
        else
        {
            i++;
            sub[j] = ft_substr(s,i,size_word(s,c,i));
            i += size_word(s,c,i);
        }
        i++;
    }
    sub[j] = 0;
    return (sub);
}

void lexer_main(t_data *data)
{
    char **command;
    command = lexer_split(data->cmd);
    int i = 0;
    while (command[i])
    {
        printf("%s\n",command[i]);
        i++;
    }

}
