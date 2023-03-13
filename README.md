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
Compile all C files to the executable `a.out` and optionally set the `BUFFER_SIZE` while compiling (here set at 42). If you do not set it here the default buffer size is set at 16 in the `get_next_line.h` file.
`cat -e` is added at the end as an optional way to check if the line end positions. 
```
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c test_gnl.c -D BUFFER_SIZE=42 && ./ a.out "sample.txt" | cat -e 
```

## Leaks
Testing for leaks can be done by uncommenting `system("leaks test.out")`in the code.

## Bonus
The bonus file is an adjustment to be able to accept different alternating file descriptors. To test open several text files and 
pass their file descriptors.

Alternitavly I have provided a make file to run the abovementioned tests.
simply run `make test`, `make bonus` and `make stdi` to quikly test the working of the function. You can adjust change the buffer size and sample teksts in the makefile.

GL&HV