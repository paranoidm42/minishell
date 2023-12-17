#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"

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
    if(ac != 1 && av != NULL)
        return (0);
    int index = found_path(env);
    if(index == -1)
        return (0);
    printf("%s\n------------\n",env[index]);
    char *cmd;
    while (1)
    {
        cmd = readline("von-> ");

        if(strncmp(cmd,"exit",5) == 0)
            return (0);

    }

}
