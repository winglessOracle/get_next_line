/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 11:44:03 by cwesseli      #+#    #+#                 */
/*   Updated: 2022/11/18 17:41:26 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
This function joines the existing staic variable string with the content
of buffer to create a long string to later split up in a part before the
new-line char and a part behind the new-line char.
Memmory is allocated for an empty string. The next step is
to iterate though the exisiting string and then the buffer and copy all
values to the return string.
*/
char	*ft_strjoin_gnl(char *passed_line, char *buffer)
{
	int		i;
	int		j;
	int		len_1;
	int		len_2;
	char	*joined_str;

	len_1 = ft_strlen(passed_line);
	len_2 = ft_strlen(buffer);
	if (len_1 == 0 && len_2 == 0)
		return (NULL);
	joined_str = (char *)malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (joined_str == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (i < len_1)
		joined_str[i++] = passed_line[j++];
	j = 0;
	while (j < len_2)
		joined_str[i++] = buffer[j++];
	joined_str[i] = '\0';
	return (free(passed_line), joined_str);
}

/*
This function takes the joined string and copies the 
the part before the (first)new-line char to a new sting and
returns it.
The first step is to determine end of the string to return. This
is either a new_line character of en null terminiator.
in case of a null terminator the return line is the passed line.
Otherwise the next step is to iterate through the string once
more and copy the values to the return string with some extra
attention for the new line character.

*/
char	*get_new_line(char *passed_line)
{
	char	*new_line;
	int		i;

	i = 0;
	while (passed_line[i] != '\n' && passed_line[i])
		i++;
	if (passed_line[i] != '\n')
		return (passed_line);
	else
	{
		new_line = (char *)malloc(sizeof(char) * (i + 2));
		if (!new_line)
			return (NULL);
	}
	i = 0;
	while (passed_line[i] != '\n' && passed_line[i])
	{
		new_line[i] = passed_line[i];
		i++;
	}
	new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

/*
This function takes the joined string and copies and returns
the part after the new-line char if it exists. The return is the
new value of the static variable to use in the next function call.
The first step is to iterate through the joined string to
find either the end of the string or a new-line char.
In case of the end of the string there is no string
left to return and the previously mallocated string is freed
and NULL is returned. Otherwise memmory is allocated for the found
return value based on the total string lenght - the distance
to the new-line char.
The next step is to iterate through the joiend string from the
new-line char till the end of the string and copy the values to
the return string. Finally free the 'old' string as it is now
replaced with the return value.
*/
char	*get_new_string(char *passed_line)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	while (passed_line[i] != '\n' && passed_line[i])
		i++;
	if (!passed_line[i] || passed_line == NULL)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(passed_line) - i));
	if (!new_str)
	{
		free(passed_line);
		passed_line = NULL;
		return (NULL);
	}
	j = 0;
	i += 1;
	while (i < ft_strlen(passed_line))
		new_str[j++] = passed_line[i++];
	new_str[j] = '\0';
	free(passed_line);
	return (new_str);
}

/*
This is a basic helper function to determine the lenght
of a string till the null terminator. In case of an
empty string it will return '0'.
*/
int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
This is a helper function to determine the presence of
a character in a string.
*/
int	ft_findchr(char *str, char c)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == c)
		return (1);
	return (0);
}
