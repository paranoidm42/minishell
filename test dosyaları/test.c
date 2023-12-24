#include "test.h"
#include <unistd.h>
void	ft_free(char **str)
{
	int i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
char	*find_path(char **env)
{
	int	i = 0;
	while(env[i])
	{
		if (ft_strncmp(env[i],"PATH=",5) == 0)
			break;
		i++;
	}
	return (ft_substr(env[i],5,ft_strlen(env[i])));
}
char	*get_path(char *str,char **env)
{
	char	**splitted_path;
	char	**splitted_cmd;
	char	*sub;
	char	*join;
	int		i;

	i = 0;
	splitted_path = ft_split(find_path(env),':');
	splitted_cmd = ft_split(str,' ');
	while(splitted_path[i])
	{
		sub = ft_strjoin(splitted_path[i],"/");
		join = ft_strjoin(sub,*splitted_cmd);
		if (!access(join, F_OK))
			break;
		free(sub);
		free(join);
		i++;
	}
	ft_free(splitted_path);
	ft_free(splitted_cmd);
	return (join);
}
void	execute_one(t_mini *data, char **env)
{
	char *path;
	int pid;
	pid = fork();
	if (pid == -1)
		perror("pid");
	else if (pid == 0)
	{
		path = get_path(data->tokenized_str[0],env);
		execve(path,ft_split(data->tokenized_str[0],' '),env);
	}
}
void	execute1(t_mini *data, char **env)
{
	char	*path;
	int	pid;
	pid = fork();
	if(pid == -1)
		perror("pid");
	else if (pid == 0)
	{
		close(data->fd[0]);
		path = get_path(data->tokenized_str[0],env);
		dup2(data->fd[1],1);
		execve(path,ft_split(data->tokenized_str[0],' '),env);
	}
	close(data->fd[1]);
}
void	execute2(t_mini *data, char **env)
{
	char	*path;
	int	pid;
	pid = fork();
	if(pid == -1)
		perror("pid");
	else if (pid == 0)
	{
		close(data->fd[1]);
		path = get_path(data->tokenized_str[1],env);
		dup2(data->fd[0],0);
		execve(path,ft_split(data->tokenized_str[1],' '),env);
	}
	close(data->fd[0]);
	close(data->fd[1]);
}
void	execute(t_mini *data, char **env)
{
	if (data->tokenized_str[1])
	{
	pipe(data->fd);
	execute1(data,env);
	waitpid(-1,NULL,0);
	execute2(data,env);
	waitpid(-1,NULL,0);
	}
	else
	{
		execute_one(data,env);
		waitpid(-1,NULL,0);
	}
}
void	lex(t_mini *data,char **env)
{
	data->tokenized_str = ft_split(data->str,'|');
	execute(data,env);
}
int	main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	t_mini *data;

	data = (t_mini *)malloc(sizeof(t_mini));
	if(!data)
		return 0;
	while(1)
	{
		data->str = ft_strdup(readline("sexgpt:"));
		if(!data->str)
			continue;
		lex(data,env);
		free(data->str);
		ft_free(data->tokenized_str);
	}
}
