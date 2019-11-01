/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtytos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 20:11:45 by mtytos            #+#    #+#             */
/*   Updated: 2019/10/20 17:39:32 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monkey_cthulhu.h"

int		fig_6(char **p)
{
	int a;
	int b;

	a = 0;
	while (a < LEN_A)
	{
		b = 0;
		while (b < LEN_B)
		{
			if (p[a][b] == '#' && p[a][b + 1] != '#')
			{
				if (a + 2 < 4 && b + 1 < 4)
				{
					if ((p[a + 1][b] == '#' && p[a + 1][b + 1] == '#' &&
						p[a + 2][b + 1] == '#') ||
						(p[a + 1][b] == '#' && p[a + 1][b + 1] == '#' &&
						p[a + 2][b] == '#'))
						return (1);
				}
			}
			b++;
		}
		a++;
	}
	return (0);
}

int		fig_7(char **p)
{
	int a;
	int b;

	a = 0;
	while (a < LEN_A)
	{
		b = 0;
		while (b < LEN_B)
		{
			if (p[a][b] == '#' && p[a][b + 1] != '#')
			{
				if (a + 2 < 4 && b - 1 >= 0)
				{
					if ((p[a + 1][b - 1] == '#' && p[a + 1][b] == '#' &&
						p[a + 2][b] == '#') ||
						(p[a + 1][b - 1] == '#' && p[a + 1][b] == '#' &&
						p[a + 2][b - 1] == '#'))
						return (1);
				}
			}
			b++;
		}
		a++;
	}
	return (0);
}

int		fig_8(char **p)
{
	int a;
	int b;

	a = 0;
	while (a < LEN_A)
	{
		b = 0;
		while (b < LEN_B)
		{
			if (p[a][b] == '#' && p[a][b + 1] != '#')
			{
				if (a + 1 < 4 && b - 1 >= 0 && b + 1 < 4)
				{
					if (p[a + 1][b - 1] == '#' && p[a + 1][b] == '#' &&
						p[a + 1][b + 1] == '#')
						return (1);
				}
			}
			b++;
		}
		a++;
	}
	return (0);
}

int		fig_9(char **p)
{
	int a;
	int b;

	a = 0;
	while (a < LEN_A)
	{
		b = 0;
		while (b < LEN_B && b + 1 < LEN_B)
		{
			if (p[a][b] == '#' && p[a][b + 1] == '#')
			{
				if (b + 3 < 4)
				{
					if (p[a][b + 2] == '#' && p[a][b + 3] == '#')
						return (1);
				}
			}
			b++;
		}
		a++;
	}
	return (0);
}

int		fig_10(char **p)
{
	int a;
	int b;

	a = 0;
	while (a < LEN_A)
	{
		b = 0;
		while (b < LEN_B && b + 1 < LEN_B)
		{
			if (p[a][b] == '#' && p[a][b + 1] == '#')
			{
				if (a + 1 < 4 && b + 2 < 4)
				{
					if ((p[a][b + 2] == '#' && p[a + 1][b] == '#') ||
						(p[a][b + 2] == '#' && p[a + 1][b + 1] == '#') ||
						(p[a][b + 2] == '#' && p[a + 1][b + 1] == '#') ||
						(p[a + 1][b + 1] == '#' && p[a + 1][b + 2] == '#'))
						return (1);
				}
			}
			b++;
		}
		a++;
	}
	return (0);
}
