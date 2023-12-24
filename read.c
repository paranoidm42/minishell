#include "minishell.h"

int found_path(char **env)
{
    int i = 0;
    while (env[i])
    {
        if(ft_strncmp(env[i],"PATH=",5) == 0)
            return (i);
        i++;
    }
    return (-1);
}

int main(int ac, char **av,char **env)
{
    t_data  *data;
    data = malloc(sizeof(t_data));

    if(ac != 1 && av != NULL)
        return (0);
    int index = found_path(env);
    if(index == -1)
        return (0);
    data->path = env[index];
    while (1)
    {
        ft_signal(1);
        data->cmd = readline("$ ");
        if (!(data->cmd))
            ft_signal(3);
        add_history(data->cmd);
        lexer_main(data);
        if(strncmp(data->cmd,"exit",5) == 0)
            return (0);
    }
    return  (1);
}
