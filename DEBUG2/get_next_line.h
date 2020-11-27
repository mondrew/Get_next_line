/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:50:44 by mondrew           #+#    #+#             */
/*   Updated: 2020/05/27 17:32:51 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
typedef struct	s_list
{
	char			*data;
	char			*fd;
	struct s_list	*next;
}				t_list;

t_list	*ft_check_stack_fd(t_list *stack, int fd);
char	*ft_add_free(char *dest, char *src);
int		ft_check_newline(char *str);
void	ft_lst_delones(t_list **stack, t_list *node);
int		ft_read_from_fd(int fd, char **str);
char	*ft_cut_line(char *str, t_list **stack, int fd);
int		ft_len_bf_nl(char *str);
int		ft_lstadd_back(t_list **stack, int fd, char *to_stack);
t_list	*ft_lstnew(int fd, char *to_stack);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_count_digits(int nbr);
void	ft_help_itoa(char *str, int digits, int n);
char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);

#endif
