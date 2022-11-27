# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*print;

	fd = 0;
	print = get_next_line(fd);
	printf("line from stdi: %s",print);
	free(print);
}
