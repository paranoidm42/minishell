
#ifndef MINISHELL_H
#define MINISHELL_H

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


typedef struct s_data
{
	char *cmd;
	char *path;
} t_data;

typedef struct s_lex
{
	char type;
	char *content;
	struct s_lex *next;

} t_lex;

typedef strutc s_envo
{
	char *title;
	char *content;
	struct s_envo;
} t_envo;

void check_signal();

#endif
