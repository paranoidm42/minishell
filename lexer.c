#include "minishell.h"


void lexer_main(t_data *data)
{
	char **swap;
    int i = 0;
    swap = ft_split(data->cmd,' ');
    while (swap[i])
    {
        printf("%s\n",swap[i]);
        i++;
    }
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
