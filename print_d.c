/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 07:41:21 by asimoes           #+#    #+#             */
/*   Updated: 2020/08/03 12:20:27 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

static char		*set_precision(char *num_str, int num, t_specifier *s, int *len)
{
	char	*newstr;
	int		p_len;

	p_len = (num < 0) ? *len - 1 : *len;
	newstr = num_str;
	if (s->is_precision && s->precision > p_len)
	{
		if (num < 0)
		{
			newstr = pad_left('0', s->precision - p_len, num_str, 1);
			newstr[0] = '-';
			newstr[s->precision - p_len] = '0';
		}
		else
		{
			newstr = pad_left('0', s->precision - p_len, num_str, 1);
		}
		*len = ft_strlen(newstr);
	}
	return (newstr);
}

static char		*width_zero(char *str, int num, t_specifier *s, int *len)
{
	if (s->flags & FLAG_ZERO &&
	(s->is_precision == 0 || (s->is_precision == 1 && s->precision < 0)))
	{
		str = pad_left('0', s->width - *len, str, 1);
		if (num < 0)
		{
			str[0] = '-';
			str[s->width - *len] = '0';
		}
	}
	else
		str = pad_left(' ', s->width - *len, str, 1);
	return (str);
}

static char		*set_width(char *str, int num, t_specifier *specifier, int *len)
{
	if (!specifier->is_width || *len >= specifier->width)
		return (str);
	if (specifier->flags & FLAG_MINUS)
		str = pad_right(' ', specifier->width - *len, str, 1);
	else
		str = width_zero(str, num, specifier, len);
	return (str);
}

static char		*set_space(char *str, int num, t_specifier *s, int *len)
{
	if (num > 0 && *len > s->width
		&& s->flags & FLAG_SPACE
		&& (s->flags & FLAG_PLUS) == 0)
		str = pad_left(' ', 1, str, 1);
	*len += 1;
	return (str);
}

void			print_d(va_list args, t_specifier *s, int *count)
{
	int		number;
	char	*number_str;
	int		len;

	number = (int)va_arg(args, int);
	if (!(number_str = ft_itoa(number)))
	{
		*count = -1;
		return ;
	}
	len = ft_strlen(number_str);
	number_str = set_precision(number_str, number, s, &len);
	if (s->flags & FLAG_PLUS && number > 0)
	{
		number_str = pad_left('+', 1, number_str, 1);
		len++;
	}
	if (s->precision == 0 && number == 0)
		number_str[--len] = '\0';
	number_str = set_width(number_str, number, s, &len);
	number_str = set_space(number_str, number, s, &len);
	ft_putstr_fd(number_str, 1);
	*count += ft_strlen(number_str);
	free(number_str);
}
