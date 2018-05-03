# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vveselov <vveselov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 17:27:16 by vveselov          #+#    #+#              #
#    Updated: 2018/03/20 01:44:22 by vveselov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vveselov.filler

BON_NAME = bonus

OBJ_DIR = ./

SRC_DIR = ./

INC_DIR = ./

SRC = filler.c get_next_line.c minilib.c goal_ch.c input_ch.c

BON_SRC = vis_bon.c get_next_line.c minilib.c input_ch.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

BON_OBJ = $(addprefix $(OBJ_DIR), $(BON_SRC:.c=.o))

HEAD = ft_printf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

bonus: $(BON_OBJ)
	gcc -o $(BON_NAME) $(BON_OBJ)

$(OBJ_DIR)%.o: %.c
	gcc -c $< -o $@ $(CFLAGS) -I $(INC_DIR)

clean:
	/bin/rm -f $(OBJ) vis_bon.o

fclean: clean
	/bin/rm -f $(NAME) $(BON_NAME)

re: fclean all

vpath %.c $(SRC_DIR)