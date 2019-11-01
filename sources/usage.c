/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtytos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:27:22 by mtytos            #+#    #+#             */
/*   Updated: 2019/10/21 20:04:03 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monkey_cthulhu.h"

void	usage(void)
{
	write(1, "usage:  There should be only one source file", 43);
	write(1, " (as an argument parameter).\n", 29);
	write(1, "\tThis file should be:\n", 23);
	write(1, "\t- every Tetrimino must exactly", 32);
	write(1, " fit in a4 by 4 chars square;\n", 30);
	write(1, "\t- all Tetrimino are separated by an newline each.\n", 52);
	exit(9);
}
