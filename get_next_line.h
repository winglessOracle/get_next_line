/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 11:43:40 by cwesseli      #+#    #+#                 */
/*   Updated: 2022/11/18 15:14:29 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

char	*get_next_line(int fd);
char	*read_and_join(int fd, char *str);
char	*ft_strjoin_gnl(char *str, char *buffer);
int		ft_strlen(char *str);
char	*get_new_line(char *str);
char	*get_new_string(char *passed_line);
int		ft_findchr(char *s, char c);
void	free_str(char *str);

#endif
