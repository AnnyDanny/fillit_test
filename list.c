/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:51:14 by gdanylov          #+#    #+#             */
/*   Updated: 2017/12/07 16:51:15 by gdanylov         ###   ########.fr       */
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

t_list	create_vika(char *data)
{
	t_list *vika;

	vika = ft_malloc(t_list);
	vika->data = data;
	vika->next = NULL;
	return (vika);
}

void	list_push_back(t_list *begin_list, char *data)
{
	t_list *list;

	list = begin_list;
	if (!list)
	{
		begin_list = create_vika(data);
		return ;
	}
	while (list->next)
		list = list->next;
	list->next = create_vika(data);
}

int	list_size(t_list *begin_list)
{
	t_list	*list;
	int size;

	list = begin_list;
	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}

void list_clear(t_list *begin_list)
{
	t_list *list;
	t_list *tmp;

	list = begin_list;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	begin_list = NULL;
}

// void	add_list(char *buf)
// {
// 	t_list *list;
// 	t_list *list_start;
// 	int i;
// 	char *input;

// 	list = 0;
// 	if (read_file(int fd))
// 	{
// 		while(buf)
// 			list_push_back(list, buf)
// 	}
// 	input = ft_memalloc(list_size(list + 1))
// 	i = 0;
// 	list_start = list;
// 	while (list)
// 	{
// 		input[i++] = list->next;
// 		// input[i++] = list->data;
// 		list = lest->next;

// 	}
// 	input[i] = '\0';
// 	buf = input;
// }