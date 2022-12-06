/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 14:26:46 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/11/21 14:26:46 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
int		ft_strlen(char *s);
int		ft_strlcpy(char *dst, char *src, int dstsize);
int		ft_strlcat(char *dst, char *src, int dstsize);
char	*ft_strchr(char *str, int c);
void	mini_cut(char *mini);
char	*read_mini_buffer(int fd, char *mini_buffer, char *buffer);

#endif