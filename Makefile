# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/03 11:31:41 by asimoes           #+#    #+#              #
#    Updated: 2020/08/21 11:09:01 by asimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c padding.c print_c.c print_d.c print_p.c print_s.c\
			print_u.c print_x.c spec_handler.c spec_utils.c
OBJ		=	$(SRCS:.c=.o)
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
NAME	=	libftprintf.a

$(NAME):
				$(MAKE) -C libft
				$(CC) -c $(CFLAGS) $(SRCS)
				ar rcs $(NAME) $(OBJ) $(shell ar -t libft/libft.a | grep .o)

all:			$(NAME)

clean:
				rm -rf $(OBJ)
				$(MAKE) -C libft fclean

fclean:			clean
				rm -rf $(NAME)

re:				fclean all
