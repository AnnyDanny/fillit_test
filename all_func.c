/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:13:15 by gdanylov          #+#    #+#             */
/*   Updated: 2017/12/10 17:13:16 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	// ft_putstr(buf);
	if (ft_check(buf) == 1)
	{
		check_figures(buf);
		ft_putstr(buf);
	}
	else
		ft_putstr("error");
	if ((ft_check) == 0)
		return (0);
	return (buf);
}

void	printvika(t_list *vika)
{
	int i;

	while (vika)
	{
		i = 0;
		while (i < 4)
		{
			printf("contentx %d\n", ((t_coordinate *)(vika->content))[i].x);
			printf("contenty %d\n\n", ((t_coordinate *)(vika->content))[i].y);
			i++;
		}
		vika = vika->next;
	}
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
	printvika(vika);
	printf("content_size %zu\n", vika->content_size);
	if (close(fd) == -1)
		return (1);
	return (0);
}

void	coordinatemin(t_coordinate c[4])
{
	int minx;
	int miny;
	int i;

	i = 0;
	minx = 3;
	miny = 3;
	while (i < 4)
	{
		if (c[i].x < minx)
			minx = c[i].x;
		if (c[i].y < miny)
			miny = c[i].y;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		c[i].x = c[i].x - minx;
		c[i].y = c[i].y - miny;
		i++;
	}
}

void	list_push_back(t_list **begin_list, t_list *new)
{
	t_list *list;

	list = *begin_list;
	if (!list)
	{
		*begin_list = new;
		return ;
	}
	while (list->next)
		list = list->next;
	list->next = new;
}

void	save_coordinateone(char *s, t_list **list, int *i)
{
	int		countx;
	int		county;
	int		arr;
	t_coordinate c[4];
	t_list *oneelem;

	countx = 0;
	county = 0;
	arr = 0;
	while (s[*i] && county < 4)
	{
		if (s[*i] == '\n' && countx == 4)
		{
			county++;
			countx = 0;
			*i += 1;
		}
		if (s[*i] == '#')
		{
			c[arr].x = countx;
			printf("countx %d\n county %d\n\n", countx, county);
			c[arr].y = county;
			arr++;
		}
		(s[*i] != '\0' && county != 4) ? *i += 1 : *i;
		countx++;
	}
	coordinatemin(c);
	oneelem = ft_lstnew(c, sizeof(t_coordinate) * 4);
	list_push_back(&(*list), oneelem);
}

t_list	*coordinate(char *s)
{
	int		i;
	int		check;
	t_list	*list;
	int blocks;

	i = 0;
	check = 0;
	list = NULL;
	blocks = 0;
	while (s[i])
	{
		save_coordinateone(s, &list, &i);
		blocks++;
		(s[i]) ? i++ : i;
	}
	create_field(blocks);
	printf("blocks %d\n\n", blocks);
	return (list);
}


char	**create_field(int blocks)
{
	int 	i;
	int 	j;
	int 	num;
	char	**field;

	i = 0;
	num = ft_sqrt(blocks * 4);
	field = (char **)malloc(sizeof(char *) * num);
	while (i < num)
	{
		field[i] = (char*)malloc(sizeof(char) * num);
		i++;
	}
	i = 0;
	while (i < num)
	{
		j = 0;
		while (j < num)
		{
			field[i][j] = '.';
			j++;
		}
		i++;
	}
	while (i--)
		printf("%s\n", field[i]);
	return (field);

}

int	check_figures(char *s)
{
	int i;
	int symbofblock;
	int ir;

	i = 0;
	while (s[i])
	{
		symbofblock = 0;
		ir = 0;
		while (s[i] && symbofblock < 20)
		{
			if (s[i] == '#')
			{
				if (s[i + 1] == '#')
					ir++;
				if (symbofblock > 0 && s[i - 1] == '#')
					ir++;
				if (symbofblock >= 5 && s[i - 5] == '#')
					ir++;
				if (symbofblock <= 16 && s[i + 5] == '#')
					ir++;
			}
			symbofblock++;
			i++;
		}
		if (!(ir == 6 || ir == 8))
		{
			printf("%d\n %d\n", i, ir);
			return (0);
		}
		(s[i]) ? i++ : i;
	}
	return (1);
}

#ifndef FILLIT_H
# define FILLIT_H

// typedef	struct s_list
// {
// 	void			*content;
// 	size_t			content_size;
// 	struct s_list	*next;
// }					t_list;

typedef struct	s_coordinate
{
	int x;
	int y;
}				t_coordinate;

char	*read_file(int fd);
int		check_figures(char *s);
t_list	*coordinate(char *s);
char	**create_field(int blocks);


#endif
