/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_field.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:57:23 by gdanylov          #+#    #+#             */
/*   Updated: 2017/12/10 15:57:24 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "fillit.h"

int		count_blocks(int blocks)
{
	int num;

	num = ft_sqrt(blocks * 4);
	return (num);
}

char	**create_field(int num)
{
	int 	i;
	int 	j;
	char	**field;
	// int 	num;

	i = 0;
	// num = ft_sqrt(blocks * 4);
	field = (char **)malloc(sizeof(char *) * (num + 1));
	field[num] = NULL;
	while (i < num)
	{
		field[i] = (char*)malloc(sizeof(char) * (num + 1));
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
		field[i][j] = '\0'; 
		i++;
	}
	return (field);
}
	// printf("%d\n %d\n", i, j);
	// while (i--)
	// 	printf("%s\n", field[i]);

int		fill_field(char **field, t_list *list, int blocks)
{
	int i;
	int j;

	i = 0;
	while (field[i])
	{
		j = 0;
		while (field[i][j])
		{
			if (field[i][j] == '.')
			{
				if (check_in_field(field, (t_coordinate *)(list->content), i, j) == 1)
				{
					add_elem_in_field(field, list, num, i, j);
					fill_field(field, list->next, blocks);
				}

			}
		}

	}
}	

char	**add_elem_in_field(char **field, t_list *list, int num, int i, int j)
{
	int x;
	int y;

	field[i][j] = list->content_size + 'A';
	while (i < 4)
	{
		x = c[i].x;
		y = c[i].y;
		// printf("printx %d\n printy %d\n", x, y);
		field[y][x] = 'A';
		i++;
	}
	i = 0;
	while (i < num)
		printf("%s\n", field[i++]);
	return (field);
}