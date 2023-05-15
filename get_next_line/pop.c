#include "stdio.h"
# include <stdlib.h>

#define BUFFER_SIZE 10

void	ft_strcat(char *str, char *sup)
{
	char *new_str;
	int i = 0, j = 0;

	while (str[i])
		i++;
	while (sup[j])
		j++;
	new_str = malloc(sizeof(char) *( i + j ));
	new_str[i+j] = '\0';
	j = -1;
	while (str[++j])
		new_str[j] = str[j];
	free(str);
	i = -1;
	j++;
	while(sup[++i])
		new_str[i + j] = sup[i];
	str = new_str;
}
int strlenn(char *str)
{
	int i;

	i = -1;
	if (!str)
		return 1;
	while (str[++i])
	{
		if (str[i] == '\n')
			return (0);
	}
	return (1);
}
char *get_next_line(int fd);
{
	char *buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	static char str;

	buff[BUFFER] = '\0';
	if (!str)
	{
		str = malloc(sizeof(char) * BUFFER_SIZE + 1);
		str[0] = '\0';
	}
	while (strlenn(str))
	{
		int len = read(fd, buff, BUFFER_SIZE);
		if (len == -1)
		{
			free(buff);
			return (0);
		}
		if (!len)
			break;
		buff[len_read] = 0;
		ft_strcat(str,buff);
	}
	free(buff);


}

int main(int a, char **b)
{
	int i = 0;
	char *str;
	int fd = open(b[1], O_RDONLY);
	while (str = get_next_line(fd))
	{
		printf("%s\n",str);
		free(str);
	}
}
