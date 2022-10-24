# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcharvel <mcharvel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 11:42:45 by mcharvel          #+#    #+#              #
#    Updated: 2022/10/24 11:42:47 by mcharvel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c utils.c utils2.c libft/*.c

OBJECTS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)
#replace, create, sort 
$(NAME): $(OBJECTS)
    AR rcs $@ $?

%.o: %.c
    $(CC) -c $(CFLAGS) $?

clean:
    rm -f $(OBJECTS)

fclean: clean
    rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
