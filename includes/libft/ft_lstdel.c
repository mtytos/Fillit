/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:25:38 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/14 16:56:38 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*next_list;

	if (alst)
	{
		while ((*alst))
		{
			next_list = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = next_list;
		}
	}
}
