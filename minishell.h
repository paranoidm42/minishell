
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


# define IS_QUOTE(x) (x == '"' || x == '\'')

typedef struct s_lex
{
	char type;
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
	struct s_envo *envo;
} t_data;


void	ft_signal();
void	lexer_main(t_data *data);
int		ft_sstrlen(char **str);
void	env_expander(t_envo *envo, char **env);

#endif
