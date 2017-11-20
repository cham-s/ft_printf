
NAME = libft.a

CC = clang

AR = ar rc

OBJ =  	ft_bzero.o \
	  	ft_memalloc.o \
	 	ft_memccpy.o \
		ft_memchr.o \
   		ft_memcmp.o \
		ft_memcpy.o \
		ft_memdel.o \
		ft_memdup.o \
		ft_memmove.o \
		ft_memset.o \
		ft_size_to_allocate.o \
		ft_splitspaces.o \
		ft_strcat.o \
		ft_strchr.o \
		ft_strclr.o \
		ft_strcmp.o \
		ft_strcpy.o \
		ft_strdel.o \
		ft_strdup.o \
		ft_strequ.o \
		ft_striter.o \
		ft_striteri.o \
		ft_strjoin.o \
		ft_strjoinfree.o \
		ft_strlcat.o \
		ft_strlen.o \
		ft_strlenchr.o \
		ft_strmap.o \
		ft_strmapi.o \
		ft_strncat.o \
		ft_strncmp.o \
		ft_strncpy.o \
		ft_strndup.o \
		ft_strnequ.o \
		ft_striter.o \
		ft_striteri.o \
		ft_strjoin.o \
		ft_strjoinfree.o \
		ft_strlcat.o \
		ft_strlen.o \
		ft_strlenchr.o \
		ft_strmap.o \
		ft_strmapi.o \
		ft_strncat.o \
		ft_strncmp.o \
		ft_strncpy.o \
		ft_strndup.o \
		ft_strnequ.o \
		ft_strnew.o \
		ft_strnjoin.o \
		ft_strnstr.o \
		ft_stronlyhas.o \
		ft_strrchr.o \
		ft_strsplit.o \
		ft_strsplitspc.o \
		ft_strstr.o \
		ft_strsub.o \
		ft_strtrim.o \
		ft_strunilen.o \
		ft_swap.o \
		ft_tablen.o \
		tabcontains.o \

CFLAGS = -c -Wall -Wextra -Werror -I ../includes
.PHONY: all clean fclean re

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)
		@ranlib $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
