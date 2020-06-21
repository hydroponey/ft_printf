/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 07:41:21 by asimoes           #+#    #+#             */
/*   Updated: 2020/06/20 07:36:37 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int	print_d(va_list args, t_specifier *specifier)
{
	int		number;
	char	*number_str;
	int		len;
	int		len_diff;
	int		i;

	number = (int)va_arg(args, int);
	number_str = ft_itoa(number);
	len = ft_strlen(number_str);
	if (specifier->width != -1 && specifier->width != 0)
	{
		if (len < specifier->width)
		{
			if (specifier->flags & FLAG_MINUS)
			{
				ft_putstr_fd(number_str, 1);
				len_diff = specifier->width - len;
				while (len_diff--)
					ft_putchar(' ');
			}
			else
			{
				len_diff = specifier->width - len;
				if (specifier->flags & FLAG_PLUS && number > 0)
					len_diff--;
				if (specifier->flags & FLAG_SPACE && number > 0)
					len_diff--;
				if (specifier->precision != -1)
				{
					len_diff -= specifier->width - specifier->precision;
					i = specifier->width - specifier->precision;
					while (i--)
						ft_putchar(' ');
				}
				while (len_diff--)
					ft_putchar((specifier->flags & FLAG_ZERO) ? '0' : ' ');
				if (specifier->flags & FLAG_PLUS && number > 0)
					ft_putchar('+');
				else if (specifier->flags & FLAG_SPACE && number > 0)
					ft_putchar(' ');
				ft_putstr_fd(number_str, 1);
			}
		}
	}
	else
	{
		if (specifier->flags & FLAG_SPACE && number > 0)
			ft_putchar(' ');
		ft_putstr_fd(number_str, 1);
	}
	return (0);
}