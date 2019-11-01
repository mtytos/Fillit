# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 22:54:25 by acthulhu          #+#    #+#              #
#    Updated: 2019/10/22 16:41:03 by acthulhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

Color_Off='\033[0m'

BRed='\033[4;31m'
BGreen='\033[3;32m'
BCyan='\033[1;36m'

NAME = fillit

SOURCES_DIRECTORY = ./sources/
SOURCE_FILES = allowed_to_insert.c \
			   board_creator.c \
			   board_insert.c \
			   clear_struct.c \
			   error_info.c \
			   find_board_size.c \
			   find_same_fig.c \
			   fresh_point.c \
			   main_func.c \
			   move_to_angle.c \
			   painter.c \
			   print_solved_board.c \
			   tetriminos_collector.c \
			   usage.c \
			   validator_0.c \
			   validator_1.c \
			   validator_2.c \
			   validator_3.c

SORCES = $(addprefix $(SOURCE_DIRECORY), $(SOURCE_FILES))

OBJECT_FILES = $(patsubst %.c, %.o, $(SOURCE_FILES))
OBJECTS_DIRECTORY = ./objects/
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECT_FILES))

LIBRARYS_DIRECTORY = ./includes/libft/
LIBRARY = -lm -L $(LIBRARYS_DIRECTORY) -lft

HEADERS_DIRECTORY = ./includes/
HEADER_FILES = monkey_cthulhu.h
HEADER = $(addprefix $(HEADERS_DIRECTORY), $(HEADER_FILES))

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) 
	@make -C $(LIBRARYS_DIRECTORY)
	@$(CC) $(FLAGS) $^ $(LIBRARY) -o $(NAME)
	@printf $(BGreen)"CONGRATULATIONS!!! Program has been created\n"$(Color_Off)

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY)%.c $(HEADER)
	@mkdir -p $(OBJECTS_DIRECTORY)
	@$(CC) $(FLAGS) -c $< -o $@ -I $(HEADERS_DIRECTORY)
	@printf $(BCyan)"$(CC)$(FLAGS) -c $< -o $@ -I $(HEADERS_DIRECTORY)\n"$(Color_Off)

clean:
	@/bin/rm -rf $(OBJECTS_DIRECTORY)
	@make delete_objects -C ./includes/libft
	@printf $(BRed)"Objects cleared\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@make full_delete -C ./includes/libft
	@printf "Binaries have been cleared\n"$(Color_Off)

re: fclean all
