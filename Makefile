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
		srcs/s_execute_2.c \
		srcs/executor.c \
		srcs/c_execute.c \
		srcs/u_execute.c \
		srcs/o_execute.c \
		srcs/x_execute.c \
		srcs/ox_funcs.c \
		srcs/ox_funcs_2.c \
		srcs/p_execute.c \
		srcs/bs_execute.c \
		srcs/bs_additional.c \
		srcs/any_type.c

SRCLIB =	libft/else/ft_atoi.c \
			libft/else/ft_count_bytes.c \
			libft/else/ft_huge_mzfk.c \
			libft/else/ft_isdigit.c \
			libft/else/ft_itoa.c \
			libft/else/ft_itoa_base.c \
			libft/else/ft_len.c \
			libft/else/ft_uhuge_mzfk.c \
			libft/else/ft_uitoa_base.c \
			libft/else/ft_ulen.c \
			libft/else/ft_upletters.c \
			libft/put/ft_putchar.c \
			libft/put/ft_putchar_fd.c \
			libft/put/ft_putnbr.c \
			libft/put/ft_putnbr_fd.c \
			libft/put/ft_putnbr_m.c \
			libft/put/ft_putstr.c \
			libft/put/ft_putunistr.c \
			libft/put/ft_putwchar.c \
			libft/put/ft_uputnbr_m.c \
			libft/str/ft_strchr.c \
			libft/str/ft_strcmp.c \
			libft/str/ft_strcpy.c \
			libft/str/ft_strncpy.c \
			libft/str/ft_strdel.c \
			libft/str/ft_strlen.c \
			libft/str/ft_strnew.c \
			libft/str/ft_unistrlen.c

OBJ = $(SRC:.c=.o) $(SRCLIB:.c=.o)

FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c includes/ft_printf.h
	gcc -c $< -o $@ $(FLAGS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all