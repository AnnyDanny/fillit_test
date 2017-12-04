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

// int	ft_counts(char *s)
// {
// 	int i;
// 	int qsymb;
// 	int counttetrims;

// 	i = 0;
// 	qsymb = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == '.' || s[i] == '#' || s[i] == '\n')
// 			i++;
// 		qsymb = i;
// 		i = 0;
// 		if (s[i] != '\n')
// 		{
// 			while (s[i] != '\n' && s[i] != '\0')
// 				i++;
// 			counttetrims++;
// 		}
// 		else
// 			return (0);
// 		return(qsymb);
// 	}
// 	return (counttetrims);
// }

int	counttetrims(char *s)
{
	int i;
	int y;
	int count;

	i = 0;
	while (s[i])
	{
		y = 0;
		count = 0;
		while (s[i] && y < 4)
		{
			if (s[i] == '\n' && count == 4)
			{
				y++;
				count = 0;
			}
			else if ((s[i] != '#' || s[i] != '.') || (s[i] != '\n' && count == 4))
				return (0);
			i++;
			count++;
		}
		if ((s[i] && s[i] != '\n') || (y != 4))
			return (0);
		i++;
	}
	return (0);
}
// 	{
// 		if (s[i] == '.' || s[i] == '#')
// 			i++;
// 		printf("%d\n", i);
// 		if (s[i] != '.' || s[i] != '#')
// 		{
// 			while (s[i] != '\n' && s[i] != '\0')
// 				i++;
// 			qtetrim++;
// 		}
// 	}
// 	one = i;
// 	printf("%d\n", one);
// 	printf("%d\n", qtetrim);
// 	return (qtetrim);
// }
// 	// if (s[i] != '\n')
// 	// {
// 	// 	while (s[i] != '\n' )
// 	// 		i++;
// 	// }
// 	// // if (s[i] == '\0')
// 	// // 	return (0);
// 	// if (qsymb == 20)
// 	// 	return (1);
// 	// else
// 	// 	return (0);

int main(int argc, char **argv)
{
	int fd;
	char *buf;
	int tetrims;
	int count;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	buf = ft_strnew(545);
	while (read(fd, buf, 544))
	{
		tetrims++;
	}
	if (tetrims != 1)
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_putstr(buf);
	// printf("%s\n", buf);
	counttetrims(buf);
	if (close(fd) == -1)
		return (1);
	return (0);
}
