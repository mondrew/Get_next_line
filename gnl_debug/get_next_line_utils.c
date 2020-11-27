/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:49:16 by mondrew           #+#    #+#             */
/*   Updated: 2020/05/26 20:13:40 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //////////////

int		ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

int		ft_count_newline(char *str)
{
	int counter;

	counter = 0;
	while (*str != '\0')
	{
		if (*str == '\n')
			counter++;
		str++;
	}
	return (counter);
}

int		ft_add_buf_to_line(char *buf, char **line, int *rest_sym)
{
	char	*tmp;

	tmp = *line;
	if (*rest_sym == 0)
	{
		if (!(tmp = ft_strjoin(*line, buf)))
			return (0);
		//if (!(tmp = ft_strdup(buf)))
		//	return (0);
	}
	else
	{
		while (*tmp != '\0')
			tmp++;
		tmp++;
		if (!(tmp = ft_strjoin(tmp, buf)))
			return (0);
	}
	free(*line);
	*line = tmp;
	//*rest_sym = ft_strlen(*line);
	*rest_sym = 0;
	return (1);
}

void	ft_change_line(char **line, int *nl_count, int *rest_sym)
{
	char	*tmp;
	int		line_len;
	int		i;

	i = 0;
	line_len = ft_strlen(*line);
	tmp = *line;
	*nl_count = ft_count_newline(*line);
	while (tmp[i] != '\n')
		i++;
	tmp[i] = '\0';
	*nl_count = *nl_count - 1;
	i++;
	*rest_sym = line_len - i;
	printf("ft_change line:\nnl_count: %d\nline_len: %d\n*rest_sym: %d\n", \
			*nl_count, line_len, *rest_sym);///////
}

int		ft_move_line(char **line, int nl_count)
{
	char *tmp;

	tmp = *line;
	while (*tmp != '\0')
		tmp++;
	if (nl_count != 0)
		tmp++;
	if (!(tmp = ft_strdup(tmp)))
		return (0);
	free(*line);
	*line = tmp;
	return (1);
}

int		ft_create_line(int fd, char **line, int *rest_sym)
{
	int		ret;
	int		nl_num;
	char	buf[BUFFER_SIZE + 1];

	while (!(nl_num = ft_count_newline(*line)))
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
			buf[ret] = '\0';
		else
			return (ret);
		printf("BUFFER before: %s\n", buf);////////
		if (!(ft_add_buf_to_line(buf, line, rest_sym)))
			return (-1);
	}
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new_str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
