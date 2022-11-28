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
int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	int			n;
	static char	*buffer;
	char		mini_buffer[BUFFER_SIZE + 1];
	int			i;
	char		*res;
	int			y;
	int			b_len;
	int			res_len;
	char		*temp;

	y = 0;
	i = 0;
	if (fd < 3 && fd != 0)
		return (NULL);
	if (buffer == NULL)
		buffer = calloc(sizeof(char), 1);
	while (ft_strchr(buffer, '\n') == NULL)
	{
		n = read(fd, mini_buffer, BUFFER_SIZE);
		if (n > 0)
		{
			mini_buffer[n] = '\0';
			buffer = ft_strjoin(buffer, mini_buffer);
		}
		else if (n == 0)
		{
			// 	// 	printf("n=%d\n", n);
			// 	// 	// if (mini_buffer[0] != '\0')
			// 	// 	// 	buffer = ft_strjoin(buffer, mini_buffer);
			// printf("mini=%s\tbuffer=%s\n", mini_buffer, buffer);
			if (buffer == NULL)
				return (NULL);
			break ;
		}
		else if (n == -1)
		{
			return (NULL);
		}
		else
			break ;
	}
	b_len = ft_strlen(buffer);
	if (b_len == 0)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	res = ft_substr(buffer, y, (i + 1));
	res_len = ft_strlen(res);
	temp = buffer;
	buffer = ft_substr(buffer, res_len, (b_len - res_len));
	free(temp);
	// res[i] = '\n';
	// printf("end_BUFFER=%s\n", buffer);
	return (res);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*sub_str;
	int		str_len;
	int		s_len;

	s_len = ft_strlen(s);
	if (start >= s_len || !*s || s[start] == '\0')
	{
		sub_str = ft_strdup("");
		return (sub_str);
	}
	if (start + len > s_len)
		str_len = s_len - start;
	else
		str_len = len;
	sub_str = malloc(sizeof(char) * (str_len + 1));
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, (s + start), str_len + 1);
	return (sub_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str_join;
	int		s1_len;
	int		s2_len;

	str_join = NULL;
	s1_len = 0;
	s2_len = 0;
	if (s1 != NULL)
		s1_len = ft_strlen(s1);
	if (s2 != NULL)
		s2_len = ft_strlen(s2);
	str_join = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str_join == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(str_join, s1, s1_len + 1);
	ft_strlcat(str_join, s2, s1_len + s2_len + 1);
	free(s1);
	return (str_join);
}

int	ft_strlcat(char *dst, char *src, int dstsize)
{
	int	len_dst;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len_dst = ft_strlen(dst);
	if (len_dst >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (dst[i])
		i++;
	while (j < dstsize - len_dst - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(src) + len_dst);
}
int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (src[s])
		s++;
	if (dstsize == 0)
		return (s);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s);
}
char	*ft_strchr(char *str, int c)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (NULL);
}
char	*ft_strdup(char *s1)
{
	char	*str;
	int		len;

	len = ft_strlen(s1);
	str = calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	memcpy(str, s1, len);
	return (str);
}
/* 

void	check_leaks(void)
{
	system("leaks -q a.out");
}

int	main(void)

{
	int fd;

	char *files[] = {
		"files/41_no_nl",                  //0
		"files/41_with_nl",                //1
		"files/42_no_nl",                  //2
		"files/42_with_nl",                //3
		"files/43_no_nl",                  //4
		"files/43_with_nl",                //5
		"files/alternate_line_nl_no_nl",   //6
		"files/alternate_line_nl_with_nl", //7
		"files/big_line_no_nl",            //8
		"files/big_line_with_nl",          //9
		"files/empty",                     //10
		"files/multiple_line_no_nl",       //11
		"files/multiple_line_with_nl",     //12
		"files/multiple_nlx5",             //13
		"files/nl",                        //14
		"file.txt",                        //15
	};
	fd = open(files[15], O_RDONLY);
	atexit(check_leaks);

	char *test = NULL;
	while (1)
	{
		test = get_next_line(fd);
		if (!test)
			break ;
		printf("GNL=%s", test);
		free(test);
	}

}
	*/

