/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:15:59 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/15 20:18:18 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_add(t_btree **root, void *item, size_t item_size,
		int (*cmpf)(void*, void*, size_t))
{
	if (!*root)
		ft_btreenew(item, item_size);
	else if (cmpf((*root)->item, item, item_size) < 0)
		ft_btree_add(&(*root)->left, item, item_size, cmpf);
	else
		ft_btree_add(&(*root)->right, item, item_size, cmpf);
}
