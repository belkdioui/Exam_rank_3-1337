// #include<fcntl.h>
// #include<stdlib.h>
// #include<stdio.h>
// #include<unistd.h>
// 	static char str[10000];
// char *get_next_line(int fd)
// {
// 	int bit;
// 	char *ret;
// 	static int i;
// 	int j;
// 	int bit_s;

// 	if(fd < 0 || BUFFER_SIZE <= 0)
// 		return(NULL);
// 	bit = 1;
// 	ret = malloc(sizeof(char) * BUFFER_SIZE +1 );
// 	ret[BUFFER_SIZE]='\0';
// 	while(bit != 0 )
// 	{
// 		bit = read(fd, ret, BUFFER_SIZE);
// 		bit_s = bit;
// 		j=0;
// 		while(bit_s)
// 		{
// 			if(ret[j] == '\n')
// 			{
// 				free(ret);
// 				return(str);
// 			}
// 			str[i] = ret[j];
// 			bit_s--;
// 			i++;
// 			j++;
// 		}
// 	}
// 	free(ret);
// 	return str;
// }

// int main()
// {
// 	int fd = open("file", O_RDWR);
// 	char *s = get_next_line(fd);
// 	printf("%s", s);
// 	printf("%s",s);
// }

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
//stdio is not needed, just let him for test with main
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*ret = malloc(9999);
	char	c;
	int		i = 0;
	int		cpt = 0;

	if (fd < 0)
		return (NULL);
	while ((cpt = read(fd, &c, 1)) > 0)
	{
		ret[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	if (i == 0 || cpt < 0)
	{
		free(ret);
		return (NULL);
	}
	ret[i] = '\0';
	return (ret);
}

// Main is here only for testing, do not let him in exam
int		main(int argc, char **argv)
{
	int 	fd = 0;
	char	*line;
	(void) argv;
	(void) argc;
		fd = open("file", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("line |%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}