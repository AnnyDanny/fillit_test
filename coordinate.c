/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 20:44:10 by gdanylov          #+#    #+#             */
/*   Updated: 2017/12/08 20:44:10 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "fillit.h"

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
			c[arr].y = county;
			arr++;
		}
		(s[*i] != '\0' && county != 4) ? *i += 1 : *i;
		countx++;
	}
	oneelem = ft_lstnew(c, sizeof(t_coordinate) * 4);
	list_push_back(&(*list), oneelem);
}

t_list	*coordinate(char *s)
{
	int		i;
	int		check;
	t_list	*list;

	i = 0;
	check = 0;
	list = NULL;
	while (s[i])
	{
		save_coordinateone(s, &list, &i);
		(s[i]) ? i++ : i;
	}
	return (list);
}