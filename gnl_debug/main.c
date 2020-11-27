/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 11:27:08 by mondrew           #+#    #+#             */
/*   Updated: 2020/05/25 22:33:46 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	int		fd;
	int		res;
	char	*str;

	fd = open("test", O_RDONLY);
	printf("File descriptor is: %d\n", fd);
	if (fd == -1)
	{
		printf("open() failed\n");
		return (0);
	}
	while ((res = get_next_line(fd, &str)) > 0)
	{
		printf("RESULT: %s\n\n", str);
	printf("res is: %d\n", res);
	}
	printf("res is: %d\n", res);
	free(str);
	return (0);
}
