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

LIB 		= libft/libft.a
NAME 		= libftprintf.a
CC 			= clang
INCLUDES 	= -I include -I libft/includes/
INC			= include/ft_printf.h
OBJDIR		= obj
AR			= ar r
OBJS 		= $(OBJDIR)/ft_printf.o\
			  $(OBJDIR)/setters.o\
			  $(OBJDIR)/setters2.o\
			  $(OBJDIR)/prints.o\
			  $(OBJDIR)/prints2.o\
			  $(OBJDIR)/utils.o\
			  $(OBJDIR)/utils2.o\
			  $(OBJDIR)/init.o\
			  $(OBJDIR)/formater.o\
			  $(OBJDIR)/fmt.o\
			  $(OBJDIR)/fmt2.o\
			  $(OBJDIR)/fmt3.o\
			  $(OBJDIR)/fmt4.o\

CFLAGS = -c -Wall -Wextra -Werror

.PHONY: all clean fclean re

VPATH = src/ft_printf

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(LIB) $(OBJS)
	cp $(LIB) .
	mv libft.a $(NAME)
	@ranlib $(NAME)

$(OBJDIR)/%.o : %.c $(INC)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@  


clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	gcc main.c -I include -I libft/includes -o printf libftprintf.a
	./printf | cat -e
