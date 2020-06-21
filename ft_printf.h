/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 11:35:07 by asimoes           #+#    #+#             */
/*   Updated: 2020/06/21 18:38:14 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DEBUG 1

# include <unistd.h>
# include <stdarg.h>
#ifdef DEBUG
# include <stdio.h>
#endif

# define ft_putchar(x)	ft_putchar_fd(x, 1)

# define FLAG_MINUS	1
# define FLAG_PLUS	2
# define FLAG_SPACE	4
# define FLAG_OCTO	8
# define FLAG_ZERO	16

typedef struct	s_specifier {
	short int	flags;
	int			width;
	int			precision;
	int			length;
	char		specifier;
	char		character;
}				t_specifier;

char	*pad_left(char c, int n, char *data);
char	*pad_right(char c, int n, char *data);

int		ft_printf(const char *format, ...);
int		parse_specifier(const char **format, va_list args, t_specifier **specifier);
void	print_c(va_list args, t_specifier *specifier, int *count);
void	print_s(va_list args, t_specifier *specifier, int *count);
void	print_d(va_list args, t_specifier *specifier, int *count);
void	print_p(va_list args, t_specifier *specifier, int *count);
void	print_u(va_list args, t_specifier *specifier, int *count);
void	print_x(va_list args, t_specifier *specifier, int *count);
void	call_spec_func(va_list args, t_specifier *specifier, int *count);
void	spec_handler(const char **format, va_list args, int *count);

#endif
