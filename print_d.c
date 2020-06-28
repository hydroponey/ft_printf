/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 07:41:21 by asimoes           #+#    #+#             */
/*   Updated: 2020/06/28 05:06:23 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

char	*set_precision(char *number, int precision, int *len)
{
	char	*newstr;

	if (precision > *len)
	{
		if (number < 0)
		{
			newstr = pad_left('0', precision - *len, number);
			newstr[0] = '-';
			newstr[precision - *len] = '0';
		}
		else
		{
			newstr = pad_left('0', precision - *len, number);
		}
		*len += precision - *len;
	}
	return (newstr);
}

void		print_d(va_list args, t_specifier *specifier, int *count)
{
	int		number;
	char	*number_str;
	char	*temp;
	int		len;

	number = (int)va_arg(args, int);
	number_str = ft_itoa(number);
	if (!number_str)
	{
		*count = -1;
		return ;
	}
	len = ft_strlen(number_str);
	number_str = set_precision(number_str, specifier->precision, &len);
	/*if (specifier->precision > len)
	{
		if (number < 0)
		{
			number_str[0] = '0';
			temp = number_str;
			number_str = pad_left('0', specifier->precision - len + 1, number_str);
			free(temp);
			number_str[0] = '-';
			len += specifier->precision - len + 1;
		}
		else
		{
			temp = number_str;
			number_str = pad_left('0', specifier->precision - len, number_str);
			free(temp);
			len += specifier->precision - len;
		}
	}*/
	if (specifier->flags & FLAG_PLUS && number > 0)
	{
		temp = number_str;
		number_str = pad_left('+', 1, number_str);
		free(temp);
		len++;
	}
	if (specifier->precision == 0 && number == 0)
	{
		number_str[len - 1] = '\0';
		len--;
	}
	if (len < specifier->width)
	{
		if (specifier->flags & FLAG_MINUS)
		{
			temp = number_str;
			number_str = pad_right(' ', specifier->width - len, number_str);
			free(temp);
		}
		else
		{
			temp = number_str;
			number_str = pad_left((specifier->flags & FLAG_ZERO && specifier->precision == -1) ? '0' : ' ', specifier->width - len, number_str);
			free(temp);
			if (number_str[specifier->width - len] == '-')
			{
				number_str[0] = '-';
				number_str[specifier->width - len] = '0';
			}
		}
	}
	if (number > 0 && len > specifier->width && specifier->flags & FLAG_SPACE)
	{
		temp = number_str;
		number_str = pad_left(' ', 1, number_str);
		free(temp);
	}
	ft_putstr_fd(number_str, 1);
	len = ft_strlen(number_str);
	free(number_str);
	*count += len;
}