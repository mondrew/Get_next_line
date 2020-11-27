/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:48:09 by mondrew           #+#    #+#             */
/*   Updated: 2020/05/29 02:59:08 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void		ft_lst_delones(t_list **stack, t_list *node)
{
	int		index;
	t_list	*tmp;

	tmp = *stack;
	index = 0;
	while (tmp != node)
	{
		tmp = tmp->next;
		index++;
	}
	if (index > 0)
		index--;
	tmp = *stack;
	while (index-- > 0)
		tmp = tmp->next;
	if (*stack == node)
		*stack = node->next;
	else
		tmp->next = node->next;
	free(node->data);
	free(node->fd);
	free(node);
}

int			ft_pull_stack(int fd, t_list **stack, char **temp_str)
{
	t_list	*find;
	char	*new_str;

	find = *stack;
	while (find != NULL)
	{
		new_str = NULL;
		if (ft_atoi(find->fd) == fd)
		{
			if ((new_str = ft_strjoin(*temp_str, find->data)))
			{
				free(*temp_str);
				*temp_str = new_str;
				ft_lst_delones(stack, find);
			}
			else
				return (-1);
		}
		if (ft_strlen_checknl(*temp_str, 2))
			break;
		find = find->next;
	}
	return (1);
}

t_list		*ft_lst_new_addback(t_list **stack, char *to_stack, int fd, int s)
{
	t_list	*tmp;
	t_list	*new;
	char	*fd_all;

	if ((!(new = malloc(sizeof(t_list)))) || \
			(!((fd_all = ft_itoa_m(fd, fd, 0)))))
		return (NULL);
	new->fd = fd_all;
	new->data = to_stack;
	new->next = NULL;
	if (s == 2)
	{
		tmp = *stack;
		if (*stack == NULL)
			*stack = new;
		while (tmp->next != NULL && *stack != NULL)
			tmp = tmp->next;
		if (*stack != NULL)
			tmp->next = new;
	}
	return (new);
}

char		*ft_cut_line(char *str, t_list **stack, int fd)
{
	char	*line;
	char	*to_stack;
	int		str_len;
	int		len_nl;

	len_nl = 0;
	str_len = ft_strlen_checknl(str, 1);
	while (str[len_nl] != '\n' && str[len_nl] != '\0')
		len_nl++;
	if (!(line = ft_substr(str, 0, len_nl)))
		return (NULL);
	if (str_len > len_nl + 1)
	{
		if (!(to_stack = ft_substr(str, len_nl + 1, str_len - len_nl - 1)))
			return (NULL);
		if (!(ft_lst_new_addback(stack, to_stack, fd, 2)))
			return (NULL);
	}
	free(str);
	return (line);
}

/*
t_list		*ft_lst_new_addback(t_list **stack, char *to_stack, int fd, int s)
{
	t_list	*tmp;
	t_list	*new;
	char	*fd_all;

	if (s == 1)
	{
		if ((!(new = malloc(sizeof(t_list)))) || \
				(!((fd_all = ft_itoa_m(fd, fd, 0)))))
			return (NULL);
		new->fd = fd_all;
		new->data = to_stack;
		new->next = NULL;
		return (new);
	}
	tmp = *stack;
	if (!(new = ft_lst_new_addback(stack, to_stack, fd, 1)))
		return (NULL);
	if (*stack == NULL)
		*stack = new;
	while (tmp->next != NULL && *stack != NULL)
		tmp = tmp->next;
	if (*stack != NULL)
		tmp->next = new;
	return (new);
}
*/
int		get_next_line(int fd, char **line)
{
	static t_list	*stack = NULL;
	char			*temp_str;
	int				ret;
	char			buf[BUFFER_SIZE + 1];
	char			*tmp;

	ret = 1;
	if (!(temp_str = ft_strjoin("", "")))
		return (-1);
	if ((ft_pull_stack(fd, &stack, &temp_str)) == -1)
		return (-1);
	while ((!(ft_strlen_checknl(temp_str, 2))) && ret != 0)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) < 0)
			return (ret);
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(temp_str, buf)))
			return (-1);
		free(temp_str);
		temp_str = tmp;
	}
	if (!(*line = ft_cut_line(temp_str, &stack, fd)))
		return (-1);
	return (ret != 0);
}
