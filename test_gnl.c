# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include "get_next_line.h"

int main(int argc, char *argv[])
{
	int 	fd;
	int 	i;
	char	*print;

	if (argc < 1)
	{
		printf("no file to read");
		printf("enter in command line");
		get_next_line(0);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{	
		perror("OPEN");
		return (1);
	}
	printf("\n\n\t--opened with succes--\n");
	print = get_next_line(fd);
	i = 0;
	while (print)
	{
		i++;
		printf("line [%02d]: %s",i, print);
		free(print);
		print = NULL;
		print = get_next_line(fd);
	}
	free(print);
	
	if (close(fd) == -1)
	{
		perror("CLOSE");
		return (1);
	}
	printf("\n\t--closed with succes--\n\n");
	//system("leaks test.out");
	return (0);
}
