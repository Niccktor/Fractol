# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/14 15:49:27 by tbeguin           #+#    #+#              #
#    Updated: 2019/03/31 01:34:03 by nicktor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAGS =  

SRC_DIR = ./src
INC_DIR	= ./inc
OBJ_DIR = ./obj

LIB_FT	= ./libft
FT_LNK	= -L $(LIB_FT) -l ft

SRC =	event.c		\
	util.c		\
	mandelbrot.c	\
	draw.c		\
	color.c		\
	main.c



OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all :
	@mkdir -p $(OBJ_DIR)
	@make -C $(LIB_FT)
	@make $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(LIB_FT) -I $(INC_DIR) $(FT_LNK) -c $< -o $@
	@echo "\033[36m$(CC) $(CFLAGS) -c $< -o $@\033[0m"

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -I $(LIB_FT) -I $(INC_DIR) $(FT_LNK) \
	-L /usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 -lm
	@echo "\033[32m$(NAME) Created\033[0m"

clean :
	@rm -Rf $(OBJ_DIR)
	@echo "\033[31mRemoved obj files\033[0m"

fclean : clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_FT)
	@echo "\033[31mRemoved $(NAME)\033[0m"

re : fclean
	@make all
