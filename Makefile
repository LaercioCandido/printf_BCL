# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvidigal <bvidigal@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/14 23:46:06 by bvidigal          #+#    #+#              #
#    Updated: 2020/07/14 23:46:06 by bvidigal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = src/*.c

OBJECTS = *.o

LIB = ft_printf.h

all: $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS) : $(SRCS) $(LIB)
	@gcc -Wextra -Werror -Wall -c -g -I . $(LIB) $(SRCS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf *.gch

re: fclean all
