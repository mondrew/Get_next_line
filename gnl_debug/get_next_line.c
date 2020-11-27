/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:48:09 by mondrew           #+#    #+#             */
/*   Updated: 2020/05/26 20:17:52 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	static int	nl_count = 0;
	static int	rest_sym = 0;
	static int	start_flag = 0;
	int			ret;

	printf("The line starting : %s\n", *line);/////
	if (start_flag == 0)
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		start_flag = 1;
	}
	//if (nl_count != 0 || ft_isascii(**line))
	//{
		if (!(ft_move_line(line, nl_count)))
			return (-1);
	printf("TEEEEEEEEEEEEEEEEST");/////
	//}
	//else
	if (nl_count == 0)
	{
		if ((ret = ft_create_line(fd, line, &rest_sym)) <= 0)
			return (ret);
	printf("The line final string: %s\n", *line);/////
	printf("The rest_sym is: %d\n", rest_sym);/////
	}
	ft_change_line(line, &nl_count, &rest_sym);
	printf("The rest_sym FIN is: %d\n", rest_sym);/////
	return (1);
}

/*
int		get_next_line(int fd, char **line)
{
	static int	nl_count;
	static int	rest_sym;
	int			ret;
	char		buf[BUFFER_SIZE + 1];

	nl_count = 0;
	rest_sym = 0;
	if (nl_count == 0)
	{
		while (nl_count == 0)
		{
			if ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
				buf[ret] = '\0';
			else
				return (ret);
			nl_count = ft_add_buf_to_line(buf, line, rest_sym);
		}
	}
	else
		ft_move_line(line, &nl_count, &rest_sym);
	ft_change_line(line, &nl_count, &rest_sym);
	nl_count--;
	return (1);
}
*/



/*
void	add_line(char **line, char *buf)
{
	int buf_len;
	int rest_len;
	int i;

	i = 0;
	buf_len = ft_strlen(buf);
	while ((*line)[i] != '\n'
	char *temp;

	temp = NULL;
}

int		get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;
	ssize_t	ret;
	int		i;

	i = 0;
	tmp = NULL;
	while ((ret = read(fd, buf, BUFFER_SIZE)) && tmp == NULL);
	{
		buf[ret] = '\0';
		if (tmp = ft_strchr(buf, '\n'))
			*line = ft_substr(buf, 0, tmp - buf);
		else
			*line = ft_strdup(buf);
		if (*line == NULL)
			return (-1);
		if (tmp)
			return (1);
		else
	}


	if (!(ret = read(fd, buf, BUFFER_SIZE)));
		return (0);
	buf[ret] = '\0';
	if (tmp = ft_strchr(buf, '\n'))
		*line = ft_strdup(buf, 0, tmp - buf);
	else
		*line = ft_substr(buf, 0, ret - 1);
	if (*line == NULL)
		return (-1);
	if (tmp)
		return (1);
	else
		
}
*/
