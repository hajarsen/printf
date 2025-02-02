# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsennane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 01:30:23 by hsennane          #+#    #+#              #
#    Updated: 2025/02/02 14:16:35 by hsennane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_print_char.c ft_print_int.c ft_print_str.c ft_printf.c ft_print_hexa.c ft_print_pointer.c ft_print_unsigned.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM  = rm -f

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
