#include "minishell.h"
#include <stdlib.h>

void	env_expander(t_envo *envo, char **env)
{
	int	i;
	int	len;
	char	**expand;
<<<<<<< HEAD
	envo = malloc(sizeof(t_envo) * ft_sstrlen(env));
=======
>>>>>>> main
	i = 0;
	len = ft_sstrlen(env);
	while (env[i] && i < len)
	{
<<<<<<< HEAD
		expand = ft_split(env[i]);
		envo->title = malloc(sizeof(char) * ft_strlen(expand[0] + 1));
		envo->content = malloc(sizeof(char) * ft_strlen(expand[1] + 1));
		envo->title = expand[0];
		envo->content = expand[1];
		envo = envo->next;
		i++;
	}
}

int main(int ac, char **av, char **env)
{
	int	i = 0;
	int	j = ft_sstrlen(env);
	t_envo	envo;

	env_expander(&envo, env);
	while (i < j)
	{
		printf("Title : %s\n", envo.title);
		printf("Content : %s\n", envo.content);
		envo = *envo.next;
	}
=======
		expand = ft_split(env[i], '=');
		envo->title = ft_strdup(expand[0]);
		envo->content =	ft_strdup(expand[1]);
		envo->next = (t_envo *)malloc(sizeof(t_envo));
		envo = envo->next;
		i++;
	}
	envo->next = NULL;
>>>>>>> main
}