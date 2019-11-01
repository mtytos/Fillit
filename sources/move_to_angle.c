/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_angle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:03:10 by acthulhu          #+#    #+#             */
/*   Updated: 2019/10/21 22:03:51 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monkey_cthulhu.h"

static void	move_top(char **tetrimino)
{
	int		top;
	int		index;
	char	*swaper;

	top = 0;
	index = 0;
	while (*tetrimino)
	{
		if (!ft_strchr(tetrimino[index++], '#'))
			top++;
		else
			break ;
	}
	if (top == 0)
		return ;
	index = 0;
	while (tetrimino[top])
	{
		swaper = tetrimino[index];
		tetrimino[index] = tetrimino[top];
		tetrimino[top++] = swaper;
		index++;
	}
}

static void	move_left(char **tetrimino)
{
	int		left;
	int		var;
	int		index;
	char	c;

	left = 3;
	index = 0;
	while (tetrimino[index])
	{
		if (ft_strchr(tetrimino[index], '#'))
			var = (int)(ft_strchr(tetrimino[index], '#') - tetrimino[index]);
		var < left ? left = var : left;
		index++;
	}
	while (*tetrimino)
	{
		index = 0;
		while ((*tetrimino)[index + left])
		{
			c = (*tetrimino)[index];
			(*tetrimino)[index] = (*tetrimino)[index + left];
			(*tetrimino)[index++ + left] = c;
		}
		tetrimino++;
	}
}

void		move_to_left_angle(char **tetrimino)
{
	move_top(tetrimino);
	move_left(tetrimino);
}
