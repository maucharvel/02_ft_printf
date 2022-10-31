# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcharvel <mcharvel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 11:42:45 by mcharvel          #+#    #+#              #
#    Updated: 2022/10/31 15:54:47 by mcharvel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_un.c \
ft_putnbrhexa.c

OBJECTS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AR = ar rcs

RM = rm -f

all : $(NAME)
#replace, create, sort 
$(NAME): $(OBJECTS)
	$(AR) $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
