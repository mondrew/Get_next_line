/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 11:27:08 by mondrew           #+#    #+#             */
/*   Updated: 2020/05/30 23:02:58 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	int		fd1;
	char	*str1;

	str1 = "";
	fd1 = open("test1", O_RDONLY);
	printf("File descriptor 1 is: %d\n", fd1);
	if (fd1 == -1)
	{
		printf("open() failed\n");
		return (0);
	}
	while (get_next_line(fd1, &str1) > 1)
	{
		printf("RESULT 1: %s\n", str1);
	}
	if (close(fd1) == -1)
	{
		printf("close() error\n");
		return (1);
	}
	free(str1);
	return (0);
}
