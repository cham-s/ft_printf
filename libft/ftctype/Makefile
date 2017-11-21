NAME = libftctype.a

CC = clang

AR = ar rc

OBJ = ft_isalnum.o \
		ft_isalpha.o \
		ft_isascii.o \
		ft_isdigit.o \
		ft_isprint.o \
		ft_isspace.o \
		ft_tolower.o \
		ft_toupper.o \

CFLAGS =  -Wall -Wextra -Werror -I ../includes
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
