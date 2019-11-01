/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:41:44 by acthulhu          #+#    #+#             */
/*   Updated: 2019/10/27 17:57:40 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monkey_cthulhu.h"

int		main(int ac, char **av)
{
	int			fd;
	size_t		size;
	t_tetrimino	*begin;
	t_position	start;
	char		**board;

	if (ac != 2)
		usage();
	fd = open(av[1], O_RDONLY);
	(fd < 0) ? usage() : 1;
	begin = tetriminos_collector(fd, &size);
	start = begin->point;
	(close(fd) == -1) ? exit(-1) : 1;
	find_same_fig(begin);
	size = find_board_size(size);
	while ((board = board_creator(size)))
	{
		if (board_insert(board, begin, start, size))
			break ;
		ft_delete_two_dimensional(&board, size++);
	}
	print_solved_board(board);
	clear_struct(&begin);
	ft_delete_two_dimensional(&board, size);
	return (0);
}
