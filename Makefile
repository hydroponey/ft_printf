# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/03 11:31:41 by asimoes           #+#    #+#              #
#    Updated: 2020/06/21 12:18:52 by asimoes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c padding.c print_c.c print_d.c print_p.c print_s.c\
			print_u.c print_x.c spec_handler.c
OBJ		=	$(SRCS:.c=.o)
NAME	=	libftprintf.a

$(NAME):
				gcc -c -Wall -Werror -Wextra libft/*.c -I libft/
				gcc -c $(SRCS)
				ar rc $(NAME) $(OBJ)
				ranlib $(NAME)
all:			$(NAME)

clean:			
				rm -rf *.o

fclean:			clean
				rm -rf $(NAME)

re:				fclean all

bonus: