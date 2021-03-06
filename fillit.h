/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:59:31 by gdanylov          #+#    #+#             */
/*   Updated: 2017/12/07 14:59:31 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
t_list	*coordinate(char *s, int *blocks);
char	**create_field(int blocks);
char	**add_elem_in_field(char **field, t_list *oneelem, int num);
int		count_blocks(int blocks);


#endif