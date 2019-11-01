/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:31:29 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/15 20:20:03 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_search(t_btree *root, void *data_ref, size_t data_size,
		int (*cmpf)(void*, void*, size_t))
{
	if (!root)
		return (NULL);
	if ((*cmpf)(root->item, data_ref, data_size) < 0)
		return (ft_btree_search(root->left, data_ref, data_size, cmpf));
	else if ((*cmpf)(root->item, data_ref, data_size) == 0)
		return (root);
	else
		return (ft_btree_search(root->right, data_ref, data_size, cmpf));
}
