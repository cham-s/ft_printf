
NAME = libftstdlib.a

CC = clang

AR = ar rc

OBJ =	dictionary.o \
		dictionary2.o \

CFLAGS = -Wall -Wextra -Werror -I ../includes
.PHONY: all clean fclean re

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)
		@ranlib $(NAME)
		cp $(NAME) ../

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) ../$(NAME)
		$(RM) $(NAME)

re: fclean all
