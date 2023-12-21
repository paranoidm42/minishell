#include "minishell.h"
int	ft_sstrlen(char **s)
{
	int	lenght;

	lenght = 0;
	if (!s)
		return (0);
	lenght = 0;
	while (s[lenght])
		lenght++;
	return (lenght);
}

static int ft_count_word(char *str)
{
    int i = 0;
    int pass = 0;
    char test;
    while (str[i])
    {
        test = str[i];
        if (str[i] == '\'' || str[i] == '\"')
        {
            pass++;
            while (str[i] != test)
                i++;
        }
        i++;
    }
    return pass;
}

char *ft_remove_some(char *str)
{

    int i;
    int j;
    char *swap;
    i = 0;
    j = 0;
    swap = malloc(sizeof(char)* ft_count_word(str) + 1);
    while (str[i])
    {
        if (str[i] != '\'' && str[i] != '\"')
        {
            swap[j] = str[i];
            j++;
        }
        i++;
    }
    swap[j] = '\0';
    return swap;
}
char *split(char *str)
{
    int i;
    int j;
    char **swap;
    char *res;
    swap = ft_split(str,' ');
    i = 0;
    j = 0;
    res = malloc(sizeof(char) * ft_sstrlen(swap) + 1);
    while (swap[i])
    {
        ft_strjoin(res,ft_remove_some(swap[i]));
        i++;
    }
    return res;
}
void lexer_main(t_data *data)
{
	char *swap;
    int i = 0;
    swap = split(data->cmd);
    printf("%s\n",swap);
    i++;

}



/*
static int comma_pass(char const *s, int i)
{
	int size;
	size = 0;
	while (s[i] && (s[i] != '\'' || s[i] != '\"'))
	{
		size++;
		i++;
	}
	return (size);
}
*/
/*
void creat_and_add(t_lex **head, char *content)
{
    t_lex *new_node = (t_lex *)malloc(sizeof(t_lex));
    if (new_node)
    {
        new_node->content = content;
        new_node->next = NULL;
        if (*head == NULL)
            *head = new_node;
        else
        {
            t_lex *last = *head;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = new_node;
        }
    }
}
*/

/*

char *ft_remove_some(char *str)
{
    int i = 0;
    int pass = 0;
    char *swap;
    while (str[i])
    {
        char test = str[i];
        if (str[i] == '\'' || str[i] == '\"')
        {
            pass++;
            while (str[i] != test)
                i++;
        }
        i++;
    }
    swap = malloc(sizeof(char) * (ft_strlen(str) - pass + 1));
    i = 0;
    int j = 0;
    while (str[i])
    {
        if (str[i] != '\'' && str[i] != '\"')
        {
            swap[j] = str[i];
            j++;
        }
        i++;
    }
    swap[j] = '\0';
    return swap;
}
*/


/*
static int	pass_comma(char const *s, char c, int i)
{
	int size;
	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
        if(!s[i])
            return 0;
	}
	return (size);
}

static char *lexer(char *s) {
    int i = 0;
    int n;
    char c;
    int j = 0;
    char *sub = malloc(sizeof(char) * (ft_strlen(s) + 1));
    while (s[i]) {
        while (s[i] == ' ')
            i++;
        c = s[i];
        if (s[i] == '\'' || s[i] == '\"') {
            n = pass_comma(s, c, i);
            ft_strjoin(sub, ft_substr(s, i, n));
            i += n;
            j += n;
            printf("%d\n",n);
        } else {
            while (s[i] && (s[i] != ' ' || s[i] != '\'' || s[i] != '\"'))
                sub[j++] = s[i++];
        }
    }
    sub[j] = '\0';
    return sub;
}*/
