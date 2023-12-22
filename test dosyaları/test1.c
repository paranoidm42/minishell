	#include "minishell.h"
	#include "fcntl.h"
	int	main(int ac, char **av)
	{
		int pid = fork();
		int fd = open("a.txt",O_RDWR | O_CREAT,0666);
		if (pid == 0)
		{
			dup2(fd,1);
			exit(0);
		}
		else if (pid > 0)
		{
		waitpid(-1,NULL,0);
		printf("CCUR");
		}
	}
