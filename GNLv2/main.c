/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 11:27:08 by mondrew           #+#    #+#             */
/*   Updated: 2020/05/29 01:28:57 by mondrew          ###   ########.fr       */
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
	int		fd2;
	int		ret1;
	int		ret2;
	char	*str1;
	char	*str2;

	str1 = NULL;
	str2 = NULL;
	fd1 = open("test1", O_RDONLY);
	printf("File descriptor 1 is: %d\n", fd1);
	if (fd1 == -1)
	{
		printf("open() failed\n");
		return (0);
	}
	fd2 = open("test2", O_RDONLY);
	printf("File descriptor 2 is: %d\n", fd2);
	if (fd2 == -1)
	{
		printf("open() failed\n");
		return (0);
	}
	ret1 = get_next_line(fd1, &str1);
	printf("RESULT 1: %s\nRET1: %d", str1, ret1);
	ret2 = get_next_line(fd2, &str2);
	printf("RESULT 2: %s\nRET2: %d", str2, ret2);

	ret1 = get_next_line(fd1, &str1);
	printf("RESULT 1: %s\nRET1: %d", str1, ret1);
	ret2 = get_next_line(fd2, &str2);
	printf("RESULT 2: %s\nRET2: %d", str2, ret2);

	ret1 = get_next_line(fd1, &str1);
	printf("RESULT 1: %s\nRET1: %d", str1, ret1);
	ret2 = get_next_line(fd2, &str2);
	printf("RESULT 2: %s\nRET2: %d", str2, ret2);

	ret1 = get_next_line(fd1, &str1);
	printf("RESULT 1: %s\nRET1: %d", str1, ret1);
	ret2 = get_next_line(fd2, &str2);
	printf("RESULT 2: %s\nRET2: %d", str2, ret2);

	if (close(fd1) == -1)
	{
		printf("close() error\n");
		return (1);
	}
	if (close(fd2) == -1)
	{
		printf("close() error\n");
		return (1);
	}
	free(str1);
	free(str2);
	return (0);
}
