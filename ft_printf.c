/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 11:34:15 by asimoes           #+#    #+#             */
/*   Updated: 2020/07/21 21:26:52 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			spec_handler(&format, args, &count);
		else
		{
			write(1, format, 1);
			count++;
			format++;
		}
	}
	va_end(args);
	return (count);
}
