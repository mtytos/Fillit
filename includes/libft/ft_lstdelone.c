/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:10:58 by acthulhu          #+#    #+#             */
/*   Updated: 2019/09/14 11:25:25 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (alst)
	{
		if ((*alst)->content)
		{
			del((*alst)->content, (*alst)->content_size);
			(*alst)->content = NULL;
		}
		free(*alst);
		*alst = NULL;
	}
}
