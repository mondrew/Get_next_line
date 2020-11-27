/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:50:44 by mondrew           #+#    #+#             */
/*   Updated: 2020/05/29 00:43:55 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	char			*data;
	char			*fd;
	struct s_list	*next;
}				t_list;

int		get_next_line(int fd, char **line);
int		ft_pull_stack(int fd, t_list **stack, char **temp_str);
void	ft_lst_delones(t_list **stack, t_list *node);
char	*ft_cut_line(char *str, t_list **stack, int fd);
t_list	*ft_lst_new_addback(t_list **stack, char *to_stack, int fd, int s);
size_t	ft_strlen_checknl(const char *s, int n);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa_m(int n, int cpy_nbr, int digits);
int		ft_atoi(const char *nptr);

#endif
