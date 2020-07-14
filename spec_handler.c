/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 11:48:05 by asimoes           #+#    #+#             */
/*   Updated: 2020/07/14 22:05:19 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

static t_specifier	*get_specifier_struct(void)
{
	t_specifier *specifier;

	if (!(specifier = (t_specifier*)malloc(sizeof(t_specifier))))
		return (NULL);
	specifier->flags = 0;
	specifier->is_width = 0;
	specifier->width = -1;
	specifier->is_precision = 0;
	specifier->precision = -1;
	specifier->length = -1;
	specifier->specifier = -1;
	specifier->character = -1;
	return (specifier);
}

void				spec_handler(const char **format, va_list args, int *count)
{
	t_specifier *specifier;

	if (!(specifier = get_specifier_struct()))
	{
		*count = -1;
		return ;
	}
	(*format)++;
	if (**format == '\0')
		return ;
	if (**format == '%')
	{
		ft_putchar_fd('%', 1);
		(*count)++;
		(*format)++;
		free(specifier);
		return ;
	}
	get_flags(format, specifier);
	get_width(format, args, specifier);
	get_precision(format, args, specifier);
	get_specifier(format, args, specifier);
	call_spec_func(args, specifier, count);
	free(specifier);
}

void				call_spec_func(va_list args, t_specifier *s, int *count)
{
	if (s->specifier == 'c')
		print_c(args, s, count);
	if (s->specifier == 's')
		print_s(args, s, count);
	if (s->specifier == 'p')
		print_p(args, s, count);
	if (s->specifier == 'd' || s->specifier == 'i')
		print_d(args, s, count);
	if (s->specifier == 'u')
		print_u(args, s, count);
	if (s->specifier == 'x' || s->specifier == 'X')
		print_x(args, s, count);
}
