NAME = libftstdio.a

CC = clang

AR = ar rc

OBJ =	ft_atoi.o \
		ft_ctoa_base.o \
		ft_itoa.o \
		ft_itoa_base.o \
		ft_ltoa_base.o \
		ft_putchar.o \
		ft_putchar_fd.o \
		ft_putendl.o \
		ft_putendl_fd.o \
		ft_putnbr.o \
		ft_putnbr_fd.o \
		ft_putnstr.o \
		ft_putstr.o \
		ft_putstr_fd.o \
		ft_putstruni.o \
		ft_putstrnuni.o \
		ft_putulong.o \
		ft_putunicode.o \
		ft_stoa_base.o \
		ft_uctoa_base.o \
		ft_uitoa.o \
		ft_uitoa_base.o \
		ft_ultoa_base.o \
		ft_ustoa_base.o \
		get_next_line.o \
		is_valid_codepoint.o \
		size_bytes_code_point.o \
		str_has_valid_codepoint.o \

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
