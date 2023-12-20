
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

typedef struct s_lex
{
	char *content;
	struct s_lex *next;

} t_lex;

typedef struct s_envo
{
	char *title;
	char *content;
	struct s_envo *next;
} t_envo;


typedef struct s_data
{
	char *cmd;
	char *path;
	struct s_lex *lex;
} t_data;




void	ft_signal(int flag);
void 	lexer_main(t_data *data);

#endif
