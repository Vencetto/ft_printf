NAME = libft.a

SRC = mem/*.c put/*.c str/*.c else/*.c lst/*.c

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(SRC)
	@echo "make for libft: Done"

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
