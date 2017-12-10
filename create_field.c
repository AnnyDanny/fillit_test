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

	i = 0;
	field = (char **)malloc(sizeof(char *) * count_blocks(num) + 1);
	field[num] = NULL;
	while (i < num)
	{
		field[i] = (char*)malloc(sizeof(char) * count_blocks(num) + 1);
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
	// while (i--)
		// printf("%s\n", field[i]);
	return (field);

}

char	**add_elem_in_field(char **field, t_list *oneelem)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < 4)
	{
		x = ((t_coordinate *)(oneelem->content))[i].x;
		y = ((t_coordinate *)(oneelem->content))[i].y;
		// printf("printx %d\n printy %d\n", x, y);
		field[y][x] = 'A';
		i++;
	}
	i = 0;
	while (i < 3)
		printf("%s\n", field[i++]);
	return (field);
}