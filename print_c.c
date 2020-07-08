/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 07:41:21 by asimoes           #+#    #+#             */
/*   Updated: 2020/07/08 17:48:07 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

void		print_nulchar(va_list args, t_specifier *specifier, int *count)
{
	if (specifier->is_width && (specifier->flags & FLAG_MINUS) == 0)
	{
		while (--specifier->width && (*count)++)
			ft_putchar(' ');
	}
	ft_putchar((char)0);
	(*count)++;
	if (specifier->is_width && specifier->flags & FLAG_MINUS)
	{
		while (--specifier->width && (*count)++)
			ft_putchar(' ');
	}
}

void		print_c(va_list args, t_specifier *specifier, int *count)
{
	char	*str;
	int		c;

	if (specifier->character != -1)
		c = specifier->character;
	else
		c = (int)va_arg(args, int);
	if (c == 0)
	{
		print_nulchar(args, specifier, count);
		return ;
	}
	if (!(str = malloc(2 * sizeof(char))))
	{
		*count = -1;
		return ;
	}
	str[0] = (char)c;
	str[1] = '\0';
	if (specifier->width > 1)
	{
		if (specifier->flags & FLAG_MINUS)
			str = pad_right(' ', specifier->width - 1, str);
		else
			str = pad_left((specifier->flags & FLAG_ZERO) ? '0' : ' ', specifier->width - 1, str);
	}
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}
