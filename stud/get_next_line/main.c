#include "stdio.h"
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "unistd.h"

#include "get_next_line_bonus.h"
/*
static int	ft_strclen(char *s, char c)
{
	int	i;

	i = -1;
	if (!s)
		return (-1);
	while (s[++i])
	{
		if (s[i] == c)
			return (i);
	}
	if (c == 0)
		return (i);
	return (-1);
}*/

int	pop(int fd1)
{
	char	*line;
	line = get_next_line(fd1);
	if (!line)
	{
		printf("%s",line);
		return 0;
	}
	else
	{
		printf("%s",line);
		free(line);
	}
	return 1;
}

int   main(int a, char **argv)
{
	(void) a;
	/*(void) argv;

	char b[1000] = "0123456789";
	//printf("%zu\n%d",ft_strlen(b),
	int j = ft_strclen(b, '4');
	char *c = ft_substr(b, j + 1, 10 - j);
	printf("%s\n",c);
    free(c);*/
	int	fd1 = open(argv[1], O_RDONLY);
	//get_next_line(fd1);
	//int fd2 = open(argv[2], O_RDONLY);
	/*int	j = 1;
	char	buff[BUFFER_SIZE + 1];
	while (j)
	{
		j = read(fd1,buff,BUFFER_SIZE);
		printf("\n%d:\n%s",j,buff);
	}
	close(fd1);*/
	int i = 1;
	int j = 0;
	while (i || j)
	{
		if (i)
		{
			//printf("\n1 :");
			i = pop(fd1);
		}
		//printf("\n\n\n");
		/*if (j)
		{
			printf("\n2 :");
			j = pop(fd2);
		}*/
	}
	/*
	i = 1;
	printf("\n");
	close (fd1);
	fd1 = open(argv[1], O_RDONLY);
	while (i)
		i = pop(fd1);
		line = get_next_line(fd2);
		printf("%s",line);
		free(line);*/
	return (0);
}
