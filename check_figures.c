/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:12:06 by gdanylov          #+#    #+#             */
/*   Updated: 2017/12/07 14:12:07 by gdanylov         ###   ########.fr       */
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

int	check_elser(char *s)
{
	int i;
	int symb;

	i = 0;
	symb = 0;
	while (symb < 21)
	{
		if (s[i] == '#')
		{
			ft_putstr("error");
			return (0);
		}
		symb++;
		i++;
	}
	return (1);
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
		while (symbofblock < 21)
		{
			if (s[i] == '#')
			{
				s[i] = '*';
				ir = 1;
				while (ir > 0)
				{
					ir = 0;
					if (s[i + 1] == '#')
					{
						s[i + 1] = '*';
						ir++;
					}
					if (i > 0 && s[i - 1] == '#')
					{
						s[i - 1] = '*';
						ir++;
					}
					if (i >= 5 && s[i - 5] == '#')
					{
						s[i - 5] = '*';
						ir++;
					}
					if (i <= 16 && s[i + 5] == '#')
					{
						s[i + 5] = '*';
						ir++;
					}
				}
			}
			symbofblock++;
			i++;
		}
		i++;
	}
	if (check_elser(s) == 0)
		return (0);
	else
		return (1);
}
