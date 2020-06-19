/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 11:35:07 by asimoes           #+#    #+#             */
/*   Updated: 2020/06/19 17:46:48 by asimoes          ###   ########.fr       */
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

# define LENGTH_HH	1
# define LENGTH_H	2
# define LENGTH_L	3
# define LENGTH_LL	4
# define LENGTH_J	5
# define LENGTH_Z	6
# define LENGTH_T	7
# define LENGTH_L	8


typedef struct	s_specifier {
	short int	flags;
	int			width;
	int			precision;
	int			length;
	char		specifier;
}				t_specifier;

int		ft_printf(const char *format, ...);
int		parse_specifier(const char **format, va_list args, t_specifier **specifier);
int		print_c(va_list args, t_specifier *specifier);
int		print_s(va_list args, t_specifier *specifier);
int		print_d(va_list args, t_specifier *specifier);
int		print_p(va_list args, t_specifier *specifier);
int		print_u(va_list args, t_specifier *specifier);
int		print_x(va_list args, t_specifier *specifier);
void	call_spec_func(va_list args, t_specifier *specifier, int *count);
void	spec_handler(const char **format, va_list args, int *count);

#endif
