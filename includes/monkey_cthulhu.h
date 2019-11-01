/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monkey_cthulhu.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:38:09 by acthulhu          #+#    #+#             */
/*   Updated: 2019/10/27 17:57:52 by acthulhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONKEY_CTHULHU_H
# define MONKEY_CTHULHU_H

# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# define LEN_A 4
# define LEN_B 4
# define AMT_DOT 12
# define AMT_HSH 4

typedef struct			s_position
{
	int					x;
	int					y;
}						t_position;

typedef struct			s_tetrimino
{
	t_position			p[4];
	t_position			point;
	char				alpha;
	struct s_tetrimino	*next;
	struct s_tetrimino	*same;
}						t_tetrimino;

t_tetrimino				*tetriminos_collector(int fd, size_t *cardinalty);
void					no_valid(void);
void					memory_allocation_error(void);
void					move_to_left_angle(char **tetrimino);
void					usage(void);
void					print_solved_board(char **p);
void					painter(char **board, t_position pos,
		t_tetrimino *element, char code);
void					find_same_fig(t_tetrimino *first);
void					fresh_point(t_position *fresh);
void					clear_struct(t_tetrimino **begin);
size_t					find_board_size(size_t value);
char					**board_creator(size_t board_size);
int						allowed_to_insert(char **board, t_position pos,
		t_tetrimino *element, size_t size);
int						board_insert(char **board, t_tetrimino *begin,
		t_position start, size_t size);
int						validate(char **p);
int						ch_row(char **p);
int						ch_err(char **p);
int						fig_1(char **p);
int						fig_2(char **p);
int						fig_3(char **p);
int						fig_4(char **p);
int						fig_5(char **p);
int						fig_6(char **p);
int						fig_7(char **p);
int						fig_8(char **p);
int						fig_9(char **p);
int						fig_10(char **p);
int						fig_11(char **p);
int						fig_12(char **p);
int						fig_13(char **p);
int						fig_14(char **p);
int						fig_15(char **p);

#endif
