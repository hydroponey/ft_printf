/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 11:48:05 by asimoes           #+#    #+#             */
/*   Updated: 2020/06/29 15:59:16 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

void	spec_handler(const char **format, va_list args, int *count)
{
	t_specifier *specifier;

	if (!(specifier = (t_specifier*)malloc(sizeof(t_specifier))))
	{
		*count = -1;
		return ;
	}
	specifier->flags = 0;
	specifier->is_width = 0;
	specifier->width = -1;
	specifier->precision = -1;
	specifier->length = -1;
	specifier->specifier = -1;
	specifier->character = -1;

	(*format)++;
	if (**format == '%')
	{
		ft_putchar_fd('%', 1);
		(*count)++;
		(*format)++;
		free(specifier);
		return ;
	}
	// Flags
	while (**format == '-' || **format == '+' || **format == ' ' || **format == '#' || **format == '0')
	{
		if (**format == '-')
			specifier->flags ^= FLAG_MINUS;
		if (**format == '+')
			specifier->flags ^= FLAG_PLUS;
		if (**format == ' ')
			specifier->flags ^= FLAG_SPACE;
		if (**format == '#')
			specifier->flags ^= FLAG_OCTO;
		if (**format == '0')
			specifier->flags ^= FLAG_ZERO;
		(*format)++;
	}
	// Width
	if (**format == '*')
	{
		specifier->is_width = 1;
		specifier->width = (int)va_arg(args, int);
		(*format)++;
	}
	else
	{
		if (**format >= '0' && **format <= '9')
		{
			specifier->is_width = 1;
			specifier->width = ft_atoi(*format);
			while (**format >= '0' && **format <= '9')
				(*format)++;
		}
	}
	// Precision
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			specifier->precision = (int)va_arg(args, int);
			(*format)++;
		}
		else
		{
			specifier->precision = ft_atoi(*format);
			while (**format >= '0' && **format <= '9')
				(*format)++;
		}
	}
	if (**format == 'c' || **format == 's' || **format == 'p' || **format == 'd' || **format == 'i' || **format == 'u' || **format == 'x' || **format == 'X')
	{
		specifier->specifier = **format;
		(*format)++;
	}
	else
	{
		if (**format >= '0' && **format <= '9')
			specifier->specifier = 'd';
		else
			specifier->specifier = 'c';
		specifier->character = **format;
		(*format)++;
	}
	call_spec_func(args, specifier, count);
	free(specifier);
}

void	call_spec_func(va_list args, t_specifier *specifier, int *count)
{
	if (specifier->specifier == 'c')
		print_c(args, specifier, count);
	if (specifier->specifier == 's')
		print_s(args, specifier, count);
	if (specifier->specifier == 'p')
		print_p(args, specifier, count);
	if (specifier->specifier == 'd' || specifier->specifier == 'i')
		print_d(args, specifier, count);
	if (specifier->specifier == 'u')
		print_u(args, specifier, count);
	if (specifier->specifier == 'x')
		print_x(args, specifier, count);
}