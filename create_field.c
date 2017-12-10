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
