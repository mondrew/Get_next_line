/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:48:09 by mondrew           #+#    #+#             */
/*   Updated: 2020/05/26 22:03:21 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static int	nl_count = 0;
	static int	rest_sym = 0;
	static int	start_flag = 0;
	int			ret;

	if (start_flag == 0)
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		start_flag = 1;
	}
	if (!(ft_move_line(line, nl_count, rest_sym)))
		return (-1);
	if (nl_count == 0)
	{
		if ((ret = ft_create_line(fd, line, &rest_sym)) <= 0)
			return (ret);
	}
	ft_change_line(line, &nl_count, &rest_sym);
	return (1);
}
