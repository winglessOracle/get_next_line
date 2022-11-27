/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/09 11:36:32 by cwesseli      #+#    #+#                 */
/*   Updated: 2022/11/18 17:31:34 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
get_next_line is a CODAM assignment (part of 42 network).
This assigment is to write a function that returns a line 
read from a file descriptor.
Repeated calls (e.g., using a loop) to your get_next_line() 
function should let you read the text file pointed to by
the file descriptor, one line at a time.
The function should return the line that was read.
If there is nothing else to read or if an error occurred,
it should return NULL. Additionally the buffer size
must be set at a default value and modifialbe through the
command line (e.g. -D BUFFER_SIZE=42).
*/

// This is a helper function to save lines when freeing memmory.
void	free_str(char *str)
{
	if (str)
		free (str);
}

/*
This function defines a buffer based on BUFFER_SIZE which is
a macro defined in the header file and set to a default value
of 16, changable in the commandline while compiling.
This buffer is on the stack as it is not passed.
Bytes read is set at one due to the fact that students
are not allowed to combine a condition and a function call in one
and the read-loop should continue till it returns 0 of untill
there is a new line character in the passed line.
In this loop a check is needed to confirm a succesfull
read (read BUFFER_SIZE + 1 characters from 
location FD to buffer) If the read is not succesfull 
(-1 return from read), NULL is returned. After a succefull read
the buffer is 'closed' with a null terminator. Then the join
function is called to join the existing (static variable) str and
the buffer into a new sting.
to the 'main' get next line function to be passed to get new line
and get new string functions.
*/
char	*read_and_join(int fd, char *passed_line)
{
	ssize_t		bytes_read;
	char		buffer[BUFFER_SIZE + 1];

	bytes_read = 1;
	while (bytes_read != 0 && ft_findchr(passed_line, '\n') == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free_str(passed_line);
			return (NULL);
		}
		if (bytes_read != 0)
		{
			buffer[bytes_read] = '\0';
			passed_line = ft_strjoin_gnl(passed_line, buffer);
			if (passed_line == NULL)
				return (NULL);
		}
	}
	return (passed_line);
}

/*
This is the start of the function. The static variable is a
string. While reading the file the buffer is continuously added
to this string (ft_strjoin_gnl) untill a new-Line character is
found in the sting. The resulting string is passed to a function
'get_new_string' where the 'left part' before a 
new-line character is subtracted to a new string which is passed back 
as the new_line return value. The joined string is now passed to the
get_new_string function where the 'right side' (till end of string) is
subtracted to a new string. The old string is freed and the new sting
is retained as a static variable for the next function call, to be joined
with the buffer.
*/
char	*get_next_line(int fd)
{
	static char	*passed_line;
	char		*return_line;

	return_line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (ft_findchr(passed_line, '\n') == 0)
	{
		passed_line = read_and_join(fd, passed_line);
		if (passed_line == NULL || passed_line[0] == '\0')
		{
			free_str (passed_line);
			passed_line = NULL;
			return (NULL);
		}
	}
	return_line = get_new_line(passed_line);
	if (!return_line || return_line[0] == '\0')
	{
		free_str(passed_line);
		passed_line = NULL;
		return (NULL);
	}
	passed_line = get_new_string(passed_line);
	return (return_line);
}
