/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:50:44 by mondrew           #+#    #+#             */
/*   Updated: 2020/05/26 20:59:26 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		ft_add_buf_to_line(char *buf, char **line, int *rest_sym);
int		ft_move_line(char **line, int nl_count, int rest_sym);
void	ft_change_line(char **line, int *nl_count, int *rest_sym);
int		ft_count_newline(char *str);
int		ft_create_line(int fd, char **line, int *rest_sym);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_isascii(int c);

#endif
