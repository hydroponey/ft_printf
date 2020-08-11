/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 11:35:07 by asimoes           #+#    #+#             */
/*   Updated: 2020/08/11 21:20:06 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DEBUG 1

# include <unistd.h>
# include <stdarg.h>

# define FLAG_MINUS	1
# define FLAG_PLUS	2
# define FLAG_SPACE	4
# define FLAG_OCTO	8
# define FLAG_ZERO	16

typedef struct {
	short int	flags;
	short int	is_width;
	int			width;
	short int	is_precision;
	int			precision;
	int			length;
	char		specifier;
	char		character;
}				t_s_data;

char			*pad_left(char c, int n, char *data);
char			*pad_right(char c, int n, char *data);

int				ft_printf(const char *format, ...);
void			get_flags(const char **format, t_s_data *s);
void			get_width(const char **format, va_list args, t_s_data *s);
void			get_specifier(const char **format, t_s_data *s);
void			get_precision(const char **format, va_list args, t_s_data *s);
void			print_c(va_list args, t_s_data *specifier, int *count);
void			print_s(va_list args, t_s_data *specifier, int *count);
void			print_d(va_list args, t_s_data *specifier, int *count);
void			print_p(va_list args, t_s_data *specifier, int *count);
void			print_u(va_list args, t_s_data *specifier, int *count);
void			print_x(va_list args, t_s_data *specifier, int *count);
void			spec_handler(const char **format, va_list args, int *count);

#endif
