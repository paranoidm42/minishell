#include "minishell.h"

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

void lexer_main(t_data *data)
{
	int i = 0;
	char **swap;
	swap = ft_split(data->cmd,' ');
	while (swap[i])
	{
		printf("%s\n",swap[i]);
		i++;
	}

}
