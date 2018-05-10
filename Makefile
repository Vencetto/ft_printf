# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzomber <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 18:34:19 by vzomber           #+#    #+#              #
#    Updated: 2018/03/08 18:34:20 by vzomber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	src/ft_printf.c

OBJ =	*.o

FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(OBJ): $(SRC) includes/ft_printf.h
	@gcc $(FLAGS) -c $(SRC)

$(NAME): $(OBJ) includes/ft_printf.h
	@make -C libft
	@mv ./libft/*.o ./
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
	@echo "make for ft_printf: Done"
	@make clean

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all