/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:49:16 by mondrew           #+#    #+#             */
/*   Updated: 2020/05/27 18:16:24 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>///////////////

t_list		*ft_check_stack_fd(t_list *stack, int fd)
{
	while (stack != NULL)
	{
		if (ft_atoi(stack->fd) == fd)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

char		*ft_add_free(char *dest, char *src)
{
	char *new_str;

	new_str = NULL;
	if (!(new_str = ft_strjoin(dest, src)))
		return (NULL);
	free(dest);
	return (new_str);
}

int			ft_check_newline(char *str)
{
	while (*str != '\0')
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

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

int			ft_read_from_fd(int fd, char **str)
{
	int		ret;
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;

	if ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
		buf[ret] = '\0';
	else
		return (ret);
	if (!(tmp = ft_strjoin(*str, buf)))
		return (-1);
	free(*str);
	*str = tmp;
	return (1);
}

char		*ft_cut_line(char *str, t_list **stack, int fd)
{
	char	*line;
	char	*to_stack;
	int		str_len;
	int		len_nl;

	str_len = ft_strlen(str);
	len_nl = ft_len_bf_nl(str);
	if (!(line = ft_substr(str, 0, len_nl)))
		return (NULL);
	if (str_len > len_nl + 1)
	{
		if (!(to_stack = ft_substr(str, len_nl + 1, str_len - len_nl - 1)))
			return (NULL);
		if (!(ft_lstadd_back(stack, fd, to_stack)))
			return (NULL);
	}
	free(str);
	return (line);
}

int			ft_len_bf_nl(char *str)
{
	int	len;

	len = 0;
	while (*str != '\n')
	{
		len++;
		str++;
	}
	return (len);
}

int			ft_lstadd_back(t_list **stack, int fd, char *to_stack)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *stack;
	if (!(new = ft_lstnew(fd, to_stack)))
		return (0);
	if (*stack == NULL)
		*stack = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

t_list		*ft_lstnew(int fd, char *to_stack)
{
	t_list	*new;
	char	*fd_all;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	if (!(fd_all = ft_itoa(fd)))
		return (NULL);
	new->fd = fd_all;
	new->data = to_stack;
	new->next = NULL;
	return (new);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	i = 0;
	substring = NULL;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup("\0"));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	substring = malloc(sizeof(char) * (len + 1));
	if (substring == NULL)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		substring[i] = s[start];
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}

char		*ft_strdup(const char *s)
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

int			ft_count_digits(int nbr)
{
	int digits;

	if (nbr == -2147483648)
		return (11);
	digits = 0;
	if (nbr < 0)
	{
		digits++;
		nbr = -nbr;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		digits++;
	}
	digits++;
	return (digits);
}

void		ft_help_itoa(char *str, int digits, int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			str[1] = '2';
			n = -147483648;
		}
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
	{
		str[digits - 1] = '0';
		return ;
	}
	while (n > 0 || (digits == 1 && n == 0 && str[digits - 1] != '-'))
	{
		str[digits-- - 1] = n % 10 + 48;
		n = n / 10;
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		digits;

	digits = ft_count_digits(n);
	str = malloc(sizeof(char) * (digits + 1));
	if (str == NULL)
		return (NULL);
	str[digits] = '\0';
	ft_help_itoa(str, digits, n);
	return (str);
}

int			ft_atoi(const char *nptr)
{
	unsigned long	nbr;
	int				sign;

	nbr = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' ||
		*nptr == '\f' || *nptr == '\v' || *nptr == '\r')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nbr = nbr * 10 + *(nptr++) - 48;
		if (sign > 0 && nbr > 9223372036854775807)
			return (-1);
		if (sign < 0 && nbr > 9223372036854775807)
			return (0);
	}
	return ((int)(nbr * sign));
}
