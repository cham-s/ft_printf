# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/02 16:30:48 by cattouma          #+#    #+#              #
#    Updated: 2016/08/06 04:21:21 by cattouma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a
CC 			= clang
LIB 		= libft/libft.a
FLAGS 		= -Wall -Werror -Wextra
INCLUDES 	= -I include -I libft/includes
INC			= include/ft_printf.h include/dict.h
OBJDIR		= obj
AR			= ar r
OBJS 		= $(OBJDIR)/ft_printf.o\


.PHONY: all clean fclean re

VPATH = src/ft_printf:src/dict

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(AR) $(LIB) $(OBJS)
	mv $(LIB) .
	mv libft.a $(NAME)

$(LIB):
	make -C libft/

$(OBJDIR)/%.o : %.c $(INC)
	@mkdir -p $(OBJDIR)
	$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all
	
test:
	gcc -Wall -Werror -Wextra main.c libftprintf.a -I include -I libft/includes -o ft_printf
