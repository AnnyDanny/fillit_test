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
#include "fillit.h"

char	***block_memory()
{
	int i;
	int j;
	char ***all_blocks;
	char *data;
	char *ptr;

	i = 0;
	j = 0;
	all_blocks = (char ***)malloc(sizeof(char **) * 26 + 
		sizeof(char *) * 26 * 4 + 
		sizeof(char) * 26 * 4 * 5);
	ptr = (char **)(all_blocks + 26);
	data = (char *)(all_blocks + 26 + 26 * 4);
	while (i < 26)
	{
		all_blocks[i] = ptr + i * 4;
		j = 0;
		while (j < 4)
		{
			all_blocks[i][j] = data + i * 4 * 5 + j * 5;
			all_blocks[i][j][4] = 0;
			j++;
		}
		i++;
	}
	return (all_blocks);
}

char	***in_arr(char *s)
{
	char ***m;
	int i;
	int numbofblocks;
	int countstr;
	int countsymbofstr;

	i = 0;
	numbofblocks = 0;
	char ***block_memory(m);
	while (s[i])
	{
		countstr = 0;
		while (countstr < 4)
		{
			countsymbofstr = 0;
			while (countsymbofstr < 4)
			{
				m[numbofblocks][countstr][countsymbofstr] = s[i];
				countsymbofstr++:
				i++;
			}
			countstr++;
			i++;
		}
		numbofblocks++;
		i++:
	}
	return (**m);
}


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
	return (check_figures(s));
}

char	*read_file(int fd)
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
	{
		// check_figures(buf);
		ft_putstr("ok\n");
	}
	else
		ft_putstr("ko\n");
	if ((ft_check) == 0)
		return (0);
	return (buf);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*vika;
	char	*buf;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	buf = read_file(fd);
	vika = coordinate(buf);
	if (close(fd) == -1)
		return (1);
	return (0);
}
