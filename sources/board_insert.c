/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:42:36 by acthulhu          #+#    #+#             */
/*   Updated: 2019/10/21 23:56:20 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monkey_cthulhu.h"

int		board_insert(char **board, t_tetrimino *begin, t_position start,
		size_t size)
{
	t_position	point;

	if (begin == NULL)
		return (1);
	point = start;
	while (point.y < (int)size)
	{
		if (point.y != start.y)
			point.x = 0;
		while (point.x < (int)size)
		{
			if (allowed_to_insert(board, point, begin, size))
			{
				(begin->next && begin->next->same) ?
					(start = begin->next->same->point) : fresh_point(&start);
				if (board_insert(board, begin->next, start, size))
					return (1);
				else
					painter(board, point, begin, '.');
			}
			point.x++;
		}
		point.y++;
	}
	return (0);
}
