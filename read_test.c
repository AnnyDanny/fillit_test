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

int		check_one(char *s, int *i)
{
	int		count;
	int		y;
	int		r;

	count = 0;
	y = 0;
	r = 0;
	while (s[*i] && y < 4)
	{
		if (s[*i] == '\n' && count == 4)
		{
			y++;
			count = 0;
			*i += 1;
		}
		else if (s[*i] && ((s[*i] != '#' && s[*i] != '.')
		|| (s[*i] != '\n' && count == 4)))
			return (0);
		(s[*i] == '#') ? r++ : r;
		(s[*i] != '\0' && y != 4) ? *i += 1 : *i;
		count++;
	}
	if ((s[*i] && s[*i] != '\n') || (y != 4) || (r != 4))
		return (0);
	return (1);
}

int		ft_check(char *s)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	while (s[i])
	{
		if (check_one(s, &i) == 0)
			return (0);
		if (s[i] == '\0')
		{
			check = 1;
			break ;
		}
		i++;
	}
	if (check == 0)
		return (0);
	return (1);
}

int		read_file(int fd)
{
	char	*buf;
	int		tetrims;

	tetrims = 0;
	buf = ft_strnew(545);
	while (read(fd, buf, 544))
		tetrims++;
	if (tetrims != 1)
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_putstr(buf);
	if (ft_check(buf) == 1)
		ft_putstr("ok\n");
	else
		ft_putstr("ko\n");
	if ((ft_check) == 0)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	read_file(fd);
	if (close(fd) == -1)
		return (1);
	return (0);
}
