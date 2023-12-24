#include "minishell.h"
#include <stdlib.h>

void	env_expander(t_envo *envo, char **env)
{
	int	i;
	int	len;
	char	**expand;
	i = 0;
	len = ft_sstrlen(env);
	while (env[i] && i < len)
	{
		expand = ft_split(env[i], '=');
		envo->title = ft_strdup(expand[0]);
		envo->content =	ft_strdup(expand[1]);
		envo->next = (t_envo *)malloc(sizeof(t_envo));
		envo = envo->next;
		i++;
	}
	envo->next = NULL;
}