# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cattouma <cattouma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/02 16:30:48 by cattouma          #+#    #+#              #
#    Updated: 2016/08/09 01:41:31 by cattouma         ###   ########.fr        #
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
			  $(OBJDIR)/spec_num.o\
			  $(OBJDIR)/dictionary.o\
			  $(OBJDIR)/dictionary2.o\


.PHONY: all clean fclean re

VPATH = src/ft_printf:src/dict

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	$(AR) $(LIB) $(OBJS)
	mv $(LIB) .
	mv libft.a $(NAME)

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
	gcc main.c libftprintf.a -I include -I libft/includes -o printf
