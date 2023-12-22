#ifndef TEST_H
# define TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
# include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"
#include <sys/ioctl.h>

typedef struct s_mini
{
	char	*str;
	char	**tokenized_str;
	int		fd[2];
}				t_mini;

#endif
