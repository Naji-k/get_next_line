/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 14:26:17 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/11/21 14:26:17 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_mini_buffer(int fd, char *mini_buffer, char *buffer)
{
	int	n;

	n = 1;
	while (n > 0 && ft_strchr(buffer, '\n') == NULL)
	{
		n = read(fd, mini_buffer, BUFFER_SIZE);
		if (n == -1)
		{
			mini_buffer[0] = '\0';
			return (free(buffer), NULL);
		}
		mini_buffer[n] = '\0';
		buffer = ft_strjoin(buffer, mini_buffer);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	mini_buffer[OPEN_MAX][BUFFER_SIZE + 1];
	int			i;

	i = 0;
	if ((fd < 3 && fd != 0) || fd > OPEN_MAX)
		return (NULL);
	buffer = malloc(sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	buffer = ft_strjoin(buffer, mini_buffer[fd]);
	if (!buffer)
		return (NULL);
	buffer = read_mini_buffer(fd, mini_buffer[fd], buffer);
	if (buffer == NULL)
		return (NULL);
	if (buffer[0] == '\0')
		return (free(buffer), NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	buffer = ft_substr(buffer, 0, (i + 1));
	mini_cut(mini_buffer[fd]);
	return (buffer);
}

void	mini_cut(char *mini)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (mini[i] != '\n' && mini[i] != '\0')
		i++;
	if (mini[i] == '\0')
		return ;
	i++;
	while (j < BUFFER_SIZE && mini[i] != '\0')
	{
		mini[j] = mini[i];
		i++;
		j++;
	}
	mini[j] = '\0';
}

char	*ft_substr(char *s, int start, int len)
{
	char	*sub_str;
	int		str_len;
	int		s_len;

	s_len = ft_strlen(s);
	if (start >= s_len || !*s || s[start] == '\0')
	{
		sub_str = malloc(sizeof(char));
		if (!sub_str)
			return (NULL);
		sub_str[0] = '\0';
		return (free(s), sub_str);
	}
	if (start + len > s_len)
		str_len = s_len - start;
	else
		str_len = len;
	sub_str = malloc(sizeof(char) * (str_len + 1));
	if (!sub_str)
		return (free(s), NULL);
	ft_strlcpy(sub_str, (s + start), str_len + 1);
	return (free(s), sub_str);
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

//  void	check_leaks(void)
// {
// 	system("leaks -q a.out");
// }
/* int	main(void)
{
	char *test;
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
	//atexit(check_leaks);
	test = NULL;
	// test = get_next_line(fd);
	// 		printf("GNL=%s", test);
	while (1)
	{
		test = get_next_line(fd);
		if (!test)
			break ;
		printf("%s", test);
		free(test);
	}
} */
