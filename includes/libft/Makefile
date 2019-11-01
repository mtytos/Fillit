# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acthulhu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/08 14:43:40 by acthulhu          #+#    #+#              #
#    Updated: 2019/10/21 23:46:29 by acthulhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean delete_objects full_delete re

Color_Off='\033[0m'

Black='\033[0;30m'
BRed='\033[1;31m'
BGreen='\033[3;32m'
Yellow='\033[0;33m'
Blue='\033[0;34m'
Purple='\033[0;35m'
Cyan='\033[0;36m'  
BWhite='\033[1;37m'

NAME = libft.a

SOURCES = ft_btree_add.c ft_btree_search.c ft_btreenew.c \
		  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c \
		  ft_itoa.c ft_atoi.c \
		  ft_list_find.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
		  ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_bzero.c \
		  ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
		  ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
		  ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
		  ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
		  ft_tolower.c ft_toupper.c \
		  get_next_line.c ft_delete_two_dimensional.c

OBJECT_FILES = $(patsubst %.c, %.o, $(SOURCES:.c=.o))
OBJDIR = ./objects/
OBJECTS = $(addprefix $(OBJDIR), $(OBJECT_FILES))

HEADERS_DIRECTORY = ../
HEADER_FILES = libft.h get_next_line.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADER_FILES))

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -rc $(NAME) $^
	@ranlib $(NAME)
	@printf $(BGreen)"\/\/\/\/\/\/\$(NAME) has been created!/\/\/\/\/\/\/\n"$(Color_Off)

$(OBJDIR)%.o: %.c $(HEADERS)
	@mkdir -p ./objects
	@$(CC) $(FLAGS) -c $< -o $@ -I $(HEADERS_DIRECTORY)
	@printf $(BWhite)"$(CC)$(FLAGS) -c $< -o $@ -I $(HEADERS_DIRECTORY)\n"$(Color_Off)

clean:
	@/bin/rm -rf $(OBJDIR)
	@printf $(BRed)"~~~~~~Objects have been deleted~~~~~~\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@printf $(BRed)"~~~~~~$(NAME) has been deleted!~~~~~~\n"$(Color_Off)

delete_objects:
	@/bin/rm -rf $(OBJDIR)

full_delete:
	@/bin/rm -f $(NAME)

re: fclean all
