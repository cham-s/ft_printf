# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cattouma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 13:59:55 by cattouma          #+#    #+#              #
#    Updated: 2016/08/09 04:29:32 by cattouma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ftlist.a

CC = clang

AR = ar rc

OBJ =	ft_lstappend.o \
		ft_lstdel.o \
		ft_lstdelmem.o \
		ft_lstdelone.o \
		ft_lstinsertafter.o \
		ft_lstiter.o \
		ft_lstlen.o \
		ft_lstmap.o \
		ft_lstnew.o \
		ft_lstnewref.o \
		ft_lstprint.o \
		ft_lstremove.o

CFLAGS = -g -c -Wall -Wextra -Werror -I includes
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
