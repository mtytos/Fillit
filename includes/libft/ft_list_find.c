/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:08:05 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/15 18:49:10 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, size_t data_size,
		int (*cmp)())
{
	t_list	*slider;

	if (!begin_list || !data_ref)
		return (NULL);
	slider = begin_list;
	while (slider)
	{
		if (cmp(slider->content, data_ref, data_size) == 0)
			return (slider);
		slider = slider->next;
	}
	return (NULL);
}
