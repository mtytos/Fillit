/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:45:28 by acthulhu          #+#    #+#             */
/*   Updated: 2019/10/22 16:51:35 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_add_and_clear(char *s1, char const *s2)
{
	char	*for_remove;

	if (s1)
	{
		for_remove = s1;
		if (!(s1 = ft_strjoin(s1, s2)))
		{
			ft_strdel(&for_remove);
			return (NULL);
		}
		ft_strdel(&for_remove);
	}
	else
	{
		if (!(s1 = ft_strdup(s2)))
			return (NULL);
	}
	return (s1);
}

static int		ft_read(t_box *hand, int fd)
{
	char		buf[BUFF_SIZE + 1];
	int			count;

	if (BUFF_SIZE < 1)
		return (0);
	while ((count = read(fd, buf, BUFF_SIZE)))
	{
		if (count == -1)
			return (0);
		buf[count] = '\0';
		if (!(hand->content = ft_add_and_clear(hand->content, buf)))
			return (0);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (1);
}

static t_box	*ft_search_or_add(t_box **begin, int fd)
{
	t_box	*slider;

	slider = *begin;
	while (slider)
	{
		if (fd == slider->fd)
			return (slider);
		slider = slider->next;
	}
	if (!(slider = (t_box*)ft_memalloc(sizeof(t_box))))
		return (NULL);
	slider->fd = fd;
	if (*begin)
		(*begin)->prev = slider;
	slider->next = *begin;
	slider->prev = NULL;
	slider->content = NULL;
	if (!(ft_read(slider, fd)))
	{
		ft_memdel((void**)&slider);
		return (NULL);
	}
	*begin = slider;
	return (slider);
}

static int		ft_insert(t_box *element, char **line)
{
	int		index;
	char	*string;

	index = 0;
	if (!element->content)
		return (0);
	while (element->content[index] != '\n' && element->content[index] != '\0')
		index++;
	if (!(*line = ft_strsub(element->content, 0, index)))
		return (-1);
	string = element->content;
	if (element->content[index] == '\0')
		--index;
	if (!(element->content = ft_strdup(element->content + index + 1)))
	{
		ft_strdel(&string);
		return (-1);
	}
	ft_strdel(&string);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_box	*begin_list = NULL;
	t_box			*elem;
	int				check;

	if (fd < 0 || !line || !(elem = ft_search_or_add(&begin_list, fd)))
		return (-1);
	if (!ft_strchr(elem->content, '\n'))
	{
		if (!ft_read(elem, fd))
			return (-1);
	}
	if (elem->content && elem->content[0] == '\0')
	{
		elem->next ? elem->next->prev = elem->prev : 0;
		(elem->prev) ? (elem->prev->next = elem->next) :
			(begin_list = elem->next);
		ft_strdel(&elem->content);
		free(elem);
		elem = NULL;
		return (0);
	}
	check = ft_insert(elem, line);
	return (check);
}
