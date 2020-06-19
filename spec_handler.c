/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 11:48:05 by asimoes           #+#    #+#             */
/*   Updated: 2020/06/19 17:46:05 by asimoes          ###   ########.fr       */
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
	specifier->width = -1;
	specifier->precision = -1;
	specifier->length = -1;
	specifier->specifier = -1;

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
			specifier->flags ^= 1;
		if (**format == '+')
			specifier->flags ^= 2;
		if (**format == ' ')
			specifier->flags ^= 4;
		if (**format == '#')
			specifier->flags ^= 8;
		if (**format == '0')
			specifier->flags ^= 16;
		(*format)++;
	}
	// Width
	if (**format == '*')
	{
		specifier->width = (int)va_arg(args, int);
		(*format)++;
	}
	else
	{
		if (**format >= '0' && **format <= '9')
		{
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
	printf("Flags: %d\n", specifier->flags);
	//printf("Length: %d\n", specifier.length);
	printf("Precision: %d\n", specifier->precision);
	printf("Width: %d\n", specifier->width);
	printf("Specifier: %c\n", specifier->specifier);
	call_spec_func(args, specifier, count);
	free(specifier);
}

void	call_spec_func(va_list args, t_specifier *specifier, int *count)
{
	if (specifier->specifier == 'c')
		*count += print_c(args, specifier);
	if (specifier->specifier == 's')
		*count += print_s(args, specifier);
	if (specifier->specifier == 'p')
		*count += print_p(args, specifier);
	if (specifier->specifier == 'd' || specifier->specifier == 'i')
		*count += print_d(args, specifier);
	if (specifier->specifier == 'u')
		*count += print_u(args, specifier);
	if (specifier->specifier == 'x')
		*count += print_x(args, specifier);
}