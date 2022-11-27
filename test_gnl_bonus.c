# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"

int main(int argc, char *argv[])
{
	int 	fd1;
	int		fd2;
	int 	fd3;
	int 	i;
	char	*print;

	if (argc < 3)
	{
		printf("not enough files to read");
		printf("enter three test files in command line");
		get_next_line(0);
		return (1);
	}
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	fd3 = open(argv[3], O_RDONLY);
	print = "testing bonus\n";
	i = 1;
	while (i < 100)
	{
		print = get_next_line(fd2);
		printf("line [%02d]: %s", i, print);
		print = get_next_line(fd2);
		printf("line [%02d]: %s", i, print);
		print = get_next_line(fd3);
		printf("line [%02d]: %s", i, print);
		i++;
		free(print);
	}
	print = NULL;
	free(print);
	close(fd1);
	close(fd2);
	close(fd3);
	//system("leaks test.out");
	return (0);
}
