/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:41:52 by gdanylov          #+#    #+#             */
/*   Updated: 2017/12/03 15:41:53 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

// #define BUF_SIZE 4096

int main(int argc, char **argv)
{
	int fd;
	char *ret;
	char *buf;
	int tetrims;
	int count;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	buf = ft_strnew(600);
	while (read(fd, buf, 599))
	{
		tetrims++;
	}
	if (tetrims != 1)
	{
		ft_putstr("error\n");
		return (0);
	}
	// buf[ret] = '\0';
	ft_putstr(buf);
	if (close(fd) == -1)
		return (1);
	return (0);
}


// int main()
// {
// 	void *buf;
// 	int handle;
// 	int bytes;

// 	buf = malloc(10);
// 	if ((handle = open("test.c", O_RDONLY)) == -1)
// 	{
// 		printf("wrong with open file.\n");
// 		return (1);
// 	}
// 	if ((bytes = read(handle, buf, 10)) == -1)
// 	{
// 		printf("wrong with read.\n");
// 		return (1);
// 	}
// 	else
// 		printf("read %d bytes.\n", bytes );
// 	return (0);
// }