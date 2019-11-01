/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_collector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:50:36 by acthulhu          #+#    #+#             */
/*   Updated: 2019/10/25 18:24:01 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monkey_cthulhu.h"

static void		turn_in(char **tetrimino, t_tetrimino *elem)
{
	t_position	axis;
	int			count;

	move_to_left_angle(tetrimino);
	axis.y = 0;
	count = 0;
	while (tetrimino[axis.y])
	{
		axis.x = 0;
		while (tetrimino[axis.y][axis.x])
		{
			if (tetrimino[axis.y][axis.x] == '#')
				elem->p[count++] = axis;
			axis.x++;
		}
		axis.y++;
	}
	elem->same = NULL;
	elem->point.x = 0;
	elem->point.y = 0;
}

static void		ft_reader(int fd, t_tetrimino *elem)
{
	char	**box;
	int		index;
	int		checker;

	if (!(box = (char**)malloc(sizeof(char*) * 5)))
		memory_allocation_error();
	box[4] = NULL;
	index = -1;
	while (++index < 4)
	{
		box[index] = NULL;
		checker = get_next_line(fd, &box[index]);
		if (checker == -1)
			memory_allocation_error();
	}
	if (*box == NULL || !validate(box))
	{
		ft_strdel(&box[index]);
		while (get_next_line(fd, &box[index]))
			ft_strdel(&box[index]);
		no_valid();
	}
	turn_in(box, elem);
	ft_delete_two_dimensional(&box, 4);
}

static size_t	count_tetrimo(int fd, t_tetrimino **beginer)
{
	t_tetrimino	*slider;
	size_t		counter;
	char		*line;
	int			check_read;

	slider = *beginer;
	counter = 0;
	while (1)
	{
		line = NULL;
		ft_reader(fd, slider);
		check_read = get_next_line(fd, &line);
		if (line && *line != '\0')
			no_valid();
		else if (line)
			ft_strdel(&line);
		slider->alpha = 'A' + counter;
		counter++;
		if (!check_read)
			return (counter);
		if (!(slider->next = (t_tetrimino*)malloc(sizeof(t_tetrimino))))
			memory_allocation_error();
		slider = slider->next;
		slider->next = NULL;
	}
}

t_tetrimino		*tetriminos_collector(int fd, size_t *cardinalty)
{
	t_tetrimino	*begin;

	if (!(begin = (t_tetrimino*)malloc(sizeof(t_tetrimino))))
		memory_allocation_error();
	begin->next = NULL;
	*cardinalty = count_tetrimo(fd, &begin);
	if (*cardinalty > 26)
		no_valid();
	return (begin);
}
