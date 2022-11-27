# get_next_line

get_next_line is a CODAM assignment (part of 42 network). The goal is to write a function that returns a line read from a file descriptor.
Repeated calls (e.g., using a loop) to your get_next_line() 
function should let you read the text file pointed to by
the file descriptor, one line at a time.
The function should return the line that was read.
If there is nothing else to read or if an error occurred,
it should return NULL. Additionally the buffer size
must be set at a default value and modifialbe through the
command line (e.g. -D BUFFER_SIZE=42).

For more information visit: [Codam.nl](https://codam.nl/) or [42 Cursus Subjects](https://github.com/Surfi89/42cursus/tree/main/Subject%20PDFs)

## Use

### Requirements
The functions are written in C and require compiling with GCC or CLANG. Several standard C libraries are used.

### Instructions
You can use the below code as an example for a main to test the function.

```
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
```
Use below comman to compile all C files to the executable `a.out` and optionally set the `BUFFER_SIZE` while compiling (here set at 42). If you do not set it here the default buffer size is set at 16 in the `get_next_line.h` file. 
`cat -e` is added at the end as an optional way to check if the line end positions. Replace the `sample.txt` with your own text.
```
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c test_gnl.c -D BUFFER_SIZE=42 && ./ a.out "sample.txt" | cat -e 
```

To test input from the command line (fd = 0) you can use the follwing simple main.
```
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

```

## Leaks
Testing for leaks can be done by uncommenting `system("leaks test.out")`in the code.

## Bonus
The bonus file is an adjustment to be able to accept different alternating file descriptors. To test open several text files and pass their file descriptors.
To test the bonus with three files you can use tis main. It will print 100 lines from three sourses.
```# include <stdio.h>
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
```

Alternitavly I have provided a make file to run the abovementioned tests.
simply run `make test`, `make bonus` and `make stdi` to quikly test the working of the function. You can adjust change the buffer size and sample teksts in the makefile.


GL&HV