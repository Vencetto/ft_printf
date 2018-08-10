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

SRC =	srcs/ft_printf.c \
		srcs/put_into_struct.c \
		srcs/additional.c \
		srcs/d_execute.c \
		srcs/d_execute_2.c \
		srcs/d_execute_3.c \
		srcs/s_execute.c \
		srcs/executor.c \
		srcs/c_execute.c \
		srcs/u_execute.c \
		srcs/o_execute.c \
		srcs/x_execute.c \
		srcs/ox_funcs.c \
		srcs/p_execute.c \
		srcs/bs_execute.c \
		srcs/bs_additional.c \
		srcs/any_type.c

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