/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 14:26:17 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/11/21 14:26:17 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*get_next_line(int fd)
{
	int			n;

	// int			counter;
	static char	*buffer;
	char		mini_buffer[BUFSIZE];
	int			i;
	char		*res;
	int			y;
	int			b_len;
	int			res_len;

	y = 0;
	i = 0;
	if (fd == -1)
		return (NULL);
	// counter = 5;
	// buffer = NULL;
	if (buffer == NULL)
		buffer = calloc(sizeof(char), 1);
	while (strchr(buffer, '\n') == NULL)
	{
		// mini_buffer = malloc(sizeof(char) * counter);
		// if (!mini_buffer)
		// 	return (NULL);
		n = read(fd, mini_buffer, BUFSIZE);
		if (n > 0)
		{
			// printf("mini=%s\n", mini_buffer);
			buffer = ft_strjoin(buffer, mini_buffer);
			// printf("BUFFER=%s\n", buffer);
		}
		else
			break ;
	}
	y = i;
	if (i != 0)
	{
		i++;
		y = i;
	}
	b_len = strlen(buffer);
	while (buffer[i] != '\n')
		i++;
	// printf("sub_str=%s\n", ft_substr(buffer, y, i));
	res = ft_substr(buffer, y, i);
	res_len = strlen(res) + 1;
	buffer = ft_substr(buffer, res_len, (b_len - res_len));
	// printf("b_len=%d\tres_len=%d\n", b_len, res_len);
	res[i] = '\0';
	// printf("end_BUFFER=%s\n", buffer);
	return (res);
	if (n == -1)
		exit(1);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	str_len;

	if (start >= strlen(s) || !*s || s[start] == '\0')
	{
		sub_str = strdup("");
		return (sub_str);
	}
	if (start + len > strlen(s))
		str_len = strlen(s) - start;
	else
		str_len = len;
	sub_str = malloc(sizeof(char) * (str_len + 1));
	if (!sub_str)
		return (NULL);
	strlcpy(sub_str, (s + start), str_len + 1);
	return (sub_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_join;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	s2_len = 0;
	if (s1 != NULL)
		s1_len = strlen(s1);
	if (s2 != NULL)
		s2_len = strlen(s2);
	str_join = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str_join)
		return (NULL);
	strlcpy(str_join, s1, s1_len + 1);
	strlcat(str_join, s2, s1_len + s2_len + 1);
	return (str_join);
}

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	if (fd < 3 && fd != 0)
		return (-1);
	printf("fd=%d\n", fd);
	printf("GNL=%s\n", get_next_line(fd));
	printf("***2ndcal***\n");
	printf("GNL=%s\n", get_next_line(fd));
	printf("***3rdcal***\n");
	printf("GNL=%s\n", get_next_line(fd));
	printf("***4thcal***\n");
	printf("GNL=%s\n", get_next_line(fd));
	printf("***5thcal***\n");
	printf("GNL=%s\n", get_next_line(fd));
	// //1st line
	// printf("GNL=%s\n", get_next_line(fd));
	// printf("GNL=%s\n", get_next_line(fd));
	// printf("GNL=%s\n", get_next_line(fd));
	// printf("GNL=%s\n", get_next_line(fd));
	// printf("GNL=%s\n", get_next_line(fd));
	return (0);
}
