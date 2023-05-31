#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
char *get_next_line(int fd)
{
	int bit;
	char *ret;
	char *str= malloc(10000);
	int i;
	int j;
	int bit_s;

	i=0;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	bit = 1;
	ret = malloc(sizeof(char) * BUFFER_SIZE +1 );
	ret[BUFFER_SIZE]='\0';
	while(bit != 0 )
	{
		bit = read(fd, ret, BUFFER_SIZE);
		bit_s = bit;
		j=0;
		while(bit_s)
		{
			if(ret[j] == '\n')
			{
				free(ret);
				return(str);
			}
			str[i] = ret[j];
			bit_s--;
			i++;
			j++;
		}
	}
	free(ret);
	return str;
}

int main()
{
	int fd = open("file", O_RDWR);
	char *s = get_next_line(fd);
	printf("%s", s);
}
