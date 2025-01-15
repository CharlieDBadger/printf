# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbolanos <cbolanos@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 13:39:06 by cbolanos          #+#    #+#              #
#    Updated: 2025/01/13 13:39:18 by cbolanos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -I.

NAME = libftprintf.a

SRC = ft_printf.c \
	utils/ft_putchar.c \
	utils/ft_putstr.c \
	utils/ft_putptr.c \
	utils/ft_putnum.c \
	utils/ft_putnum_abs.c \
	utils/ft_putn_hexm.c \
	utils/ft_putn_hexc.c \
	utils/ft_itoa.c \
	utils/ft_strncmp.c \
	utils/ft_strchr.c

OBJS = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJS)
	ar rcs $(NAME) $^

$(OBJS): %.o: %.c Makefile ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

