#include "stdio.h"
#include <unistd.h>
# include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif


int ft_strlen(char *str, char c)
{
	int i = -1;

	if (!str)
		return (-1);
	while (str[++i])
	{
		if (str[i] == c)
			return (i);
	}
	if (c == 0)
		return (i);
	return (-1);
}

char *ft_strndup(char *str, int n)
{
	int i = -1;
	char *ret = malloc(n + 1);
	while (++i < n)
		ret[i] = str[i];
	ret[i] = 0;
	return (ret);
}

char *ft_strdup(char *str)
{
	char *ret;
	int i = -1;
	if (!str)
		return (0);
	while (str[++i])
		;
	ret = malloc(i + 1);
	ret[i] = 0;
	while (--i >= 0)
		ret[i] = str[i];
	return (ret);
}

char *ft_strcat(char *s, char *buf)
{
	int i = -1, j = -1;
	char *ret;

	if (!s)
		return (ft_strdup(buf));
	while (s[++i])
		;
	while (buf[++j])
		;
	ret = malloc(i + j + 1);
	i = -1;
	while (s[++i])
		ret[i] = s[i];
	j = -1;
	while (buf[++j])
		ret[i + j] = buf[j];
	ret[i + j] = 0;
	return (ret);
}

char *get_next_line(int fd)
{
	int len = 0;
	static char *s;
	char buf[BUFFER_SIZE + 1], *temp, *temp2;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (ft_strlen(s, '\n') == -1)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
			return (0);
		if (len == 0)
			break ;
		buf[len] = 0;
		temp = ft_strcat(s, buf);
		free(s);
		s = ft_strdup(temp);
		free(temp);
	}
	if (!s)
		return (0);
	if (ft_strlen(s, '\n') == -1)
	{
		temp = ft_strdup(s);
		free(s);
		s = 0;
		return (temp);
	}
	temp = ft_strndup(s, ft_strlen(s, '\n') + 1);
	temp2 = ft_strdup(s + ft_strlen(s, '\n') + 1);
	free(s);
	s = ft_strdup(temp2);
	free(temp2);
	return (temp);
}
/*
int main(int a, char **b)
{
	char *str = "hello how are you\n today is a good day\n i am happy\n";
	// printf("%s\n",ft_strndup(str,ft_strlen(str,'\0')));
	int fd = open(b[1], O_RDONLY);
	while (str)
	{
		str = get_next_line(fd);
		printf("%s",str);
		if (!str)
			break ;
		free(str);
	}
	free(str);
	return (0);
}
*/
