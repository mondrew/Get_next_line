/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:48:09 by mondrew           #+#    #+#             */
/*   Updated: 2020/05/27 18:16:30 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> /////////

int		get_next_line(int fd, char **line)
{
	static t_list	*stack = NULL;
	char			*temp_str;
	t_list			*tmp_lst;
	int				ret;

	if (!(temp_str = ft_strdup("")))
		return (-1);
	while ((tmp_lst = ft_check_stack_fd(stack, fd)))
	{
		if ((temp_str = ft_add_free(temp_str, tmp_lst->data)))
			ft_lst_delones(&stack, tmp_lst);
		else
			return (-1);
		if (ft_check_newline(temp_str))
			break;
	}
	while (!(ft_check_newline(temp_str)))
	{
		if ((ret = ft_read_from_fd(fd, &temp_str)) <= 0)
			return (ret);
	}
	if (!(*line = ft_cut_line(temp_str, &stack, fd)))
		return (-1);
	return (1);
}
