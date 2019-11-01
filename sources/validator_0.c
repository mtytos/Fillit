/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtytos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 08:50:21 by mtytos            #+#    #+#             */
/*   Updated: 2019/10/20 17:55:07 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monkey_cthulhu.h"

int		ch_row(char **p)
{
	int dot;
	int hsh;
	int a;
	int b;

	dot = 0;
	hsh = 0;
	a = 0;
	while (a < LEN_A)
	{
		if (p[a][4] != '\0')
			return (0);
		b = 0;
		while (b < LEN_B)
		{
			if (p[a][b] == '.')
				dot++;
			if (p[a][b] == '#')
				hsh++;
			b++;
		}
		a++;
	}
	return ((dot == AMT_DOT && hsh == AMT_HSH) ? 1 : 0);
}

int		ch_err(char **p)
{
	int total;
	int a;
	int b;

	if (p[4] != NULL)
		return (0);
	total = 0;
	a = 0;
	while (p[a])
	{
		b = 0;
		while (p[a][b])
			b++;
		total += b;
		a++;
	}
	return ((a == 4 && total == 16) ? 1 : 0);
}

int		validate(char **p)
{
	if (ch_err(p))
	{
		if (ch_row(p) && (fig_1(p) || fig_2(p) || fig_3(p) || fig_4(p) ||
			fig_5(p) || fig_6(p) || fig_7(p) || fig_8(p) || fig_9(p) ||
			fig_10(p) || fig_11(p) || fig_12(p) || fig_13(p) ||
			fig_14(p) || fig_15(p)))
			return (1);
	}
	return (0);
}
