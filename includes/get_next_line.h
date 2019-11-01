/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:37:45 by acthulhu          #+#    #+#             */
/*   Updated: 2019/10/22 16:16:53 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1000

# include "libft.h"
# include <unistd.h>
# include <sys/uio.h>

typedef struct		s_box
{
	int				fd;
	char			*content;
	struct s_box	*next;
	struct s_box	*prev;
}					t_box;

int					get_next_line(const int fd, char **line);

#endif
