# get_next_liner

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

## Usage

Requirements
The functions are written in C and require compiling with GCC or CLANG. Several standard C libraries are used.

Instructions
1. Create a main entry point.
Add the following code to a `main.c` file, in the root directory:

```
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include "get_next_line.h"

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
		printf("\033[0;31m");
		perror("OPEN");
		printf("\033[0m");
		return (1);
	}
	printf("\033[0;32m");
	printf("\n\n\t--opened with succes--\n");
	printf("\033[0m");
	print = get_next_line(fd);
	i = 0;
	while (print)
	{
		i++;
		printf("line [%02d]: %s",i, print);
		print = NULL;
		free(print);
		print = get_next_line(fd);
	}
	
	if (close(fd) == -1)
	{
		printf("\033[0;31m");
		perror("CLOSE");
		printf("\033[0m");
		return (1);
	}
	printf("\033[0;32m");
	printf("\n\t--closed with succes--\n\n");
	printf("\033[0m");

	//system("leaks test.out");
	return (0);
}
```
## Use
Compile all C files to the executable a.out, set the BUFFER_SIZE (now set at 42). cat -e is added at the end as an optional way to check if the line end positions. Replace the sample.txt with your own text.
```
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c test_gnl.c -D BUFFER_SIZE=42 && ./ a.out "sample.txt" | cat -e 
```
## Bonus
too follow

## Standsard input
too follow

## testing
Testing for leaks can be done by uncommenting leaks in the code. 
