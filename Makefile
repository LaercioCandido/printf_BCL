# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvidigal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/05 00:00:10 by bvidigal          #+#    #+#              #
#    Updated: 2020/05/05 00:01:00 by bvidigal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Werror -Wextra
HEADER = libftprintf.h
NAME =  libftprintf.a
SRC =	ft_puthex.c \
			ft_putnbr.c\
			ft_putchar.c\
			ft_isnum.c\
			ft_atoi.c\
			ft_memset.c\
			ft_bzero.c\
			ft_printf.c\
			ft_strlen.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created!"
	@ranlib $(NAME)
	@echo "$(NAME) created!"

%.o: %.c
	@gcc $(FLAG) -I includes -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
