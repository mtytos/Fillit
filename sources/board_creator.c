/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 10:43:03 by acthulhu          #+#    #+#             */
/*   Updated: 2019/10/25 18:03:44 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monkey_cthulhu.h"

char	**board_creator(size_t board_size)
{
	size_t	num;
	char	**board;

	if (!(board = (char**)malloc(sizeof(char*) * (board_size + 1))))
		memory_allocation_error();
	num = 0;
	while (num < board_size)
	{
		if (!(board[num] = ft_strnew(board_size)))
			memory_allocation_error();
		ft_memset(board[num], '.', board_size);
		num++;
	}
	board[num] = NULL;
	return (board);
}
