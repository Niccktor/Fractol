# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/14 15:49:27 by tbeguin           #+#    #+#              #
#    Updated: 2019/04/04 22:39:25 by tbeguin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ofast


SRC_DIR = ./src
INC_DIR	= ./inc
OBJ_DIR = ./obj

LIB_FT	= ./libft
FT_LNK	= -L $(LIB_FT) -l ft

SRC = main.c		\
	  mandelbrot.c	\
	  draw.c		\
	  color.c		\
	  util.c		\
	  julia.c		\
	  math.c		\
	  mouse_event.c	\
	  key_event.c	


OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all :
	@mkdir -p $(OBJ_DIR)
	@make -C $(LIB_FT)
	@make $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(LIB_FT) -I $(INC_DIR) -c $< -o $@
	@echo "\033[36m$(CC) $(CFLAGS) -c $< -o $@\033[0m"

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit \
		$(FT_LNK) $(OBJ) -o $(NAME)
	@echo "\033[32m$(NAME) Created\033[0m"

clean :
	@rm -Rf $(OBJ_DIR)
	@echo "\033[31mRemoved obj files\033[0m"

fclean : clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_FT)
	@echo "\033[31mRemoved $(NAME)"

re : fclean
	make $(all)

.PHONY: all clean fclean re
