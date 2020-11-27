/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:50:44 by mondrew           #+#    #+#             */
/*   Updated: 2020/05/29 03:12:54 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int					get_next_line(int fd, char **line);
typedef struct		s_list
{
	char			*data;
	char			*fd;
	struct s_list	*next;
}					t_list;

int					foo(char **temp_str, t_list **stack, int fd);
void				ft_lst_delones(t_list **stack, t_list *node);
char				*ft_cut_line(char *str, t_list **stack, int fd);
t_list				*ft_lstnew_addback(t_list **stack, int fd, char *to_stack, \
					int n);
size_t				ft_strlen_checknl(const char *s, int n);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_itoa(int n, int num);
int					ft_atoi(const char *nptr);

#endif
