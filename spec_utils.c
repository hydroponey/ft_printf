/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:00:49 by asimoes           #+#    #+#             */
/*   Updated: 2020/07/14 22:07:48 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

void	get_flags(const char **format, t_specifier *specifier)
{
	while (**format == '-' || **format == '+' || **format == ' ' ||
			**format == '#' || **format == '0')
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
}

void	get_width(const char **format, va_list args, t_specifier *specifier)
{
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
	if (specifier->is_width && specifier->width < 0)
	{
		specifier->width *= -1;
		if ((specifier->flags & FLAG_MINUS) == 0)
			specifier->flags ^= FLAG_MINUS;
	}
}

void	get_precision(const char **format, va_list args, t_specifier *specifier)
{
	if (**format == '.')
	{
		specifier->is_precision = 1;
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
}

void	get_specifier(const char **format, va_list args, t_specifier *specifier)
{
	if (**format == 'c' || **format == 's' || **format == 'p' ||
		**format == 'd' || **format == 'i' || **format == 'u' ||
		**format == 'x' || **format == 'X')
	{
		specifier->specifier = **format;
		(*format)++;
	}
	else if (**format != '\0')
	{
		if (**format >= '0' && **format <= '9')
			specifier->specifier = 'd';
		else
			specifier->specifier = 'c';
		specifier->character = **format;
		(*format)++;
	}
}
