/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 07:41:21 by asimoes           #+#    #+#             */
/*   Updated: 2020/07/09 14:11:52 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

char			*x_pad_left(char c, int n, char *data)
{
	char	padding[n + 1];
	char	*padded_string;

	ft_bzero(padding, n + 1);
	while (n--)
		padding[n] = c;
	padded_string = ft_strjoin(padding, data);
	free(data);
	return (padded_string);
}

char			*x_pad_right(char c, int n, char *data)
{
	char	padding[n + 1];
	char	*padded_string;

	ft_bzero(padding, n + 1);
	while (n--)
		padding[n] = c;
	padded_string = ft_strjoin(data, padding);
	free(data);
	return (padded_string);
}

char			*get_hex_str(unsigned int number, short int capitalize)
{
	char			*str;
	int				i;
	char			cur[2];
	int				temp;

	if (number == 0)
	{
		if (!(str = malloc(2)))
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	capitalize = (capitalize) ? 55 : 87;
	if (!(str = malloc(1)))
		return (NULL);
	str[0] = '\0';
	i = 0;
	while (number != 0)
	{
		temp = number % 16;
		cur[0] = (temp < 10) ? temp + 48 : temp + capitalize;
		cur[1] = '\0';
		str = ft_strjoin(cur, str);
		number = number / 16;
	}
	return (str);
}

static char		*set_precision(char *num_str, int precision)
{
	int len;

	len = ft_strlen(num_str);
	if (precision != -1 && precision > len)
		num_str = pad_left('0', precision - len, num_str, 1);
	return (num_str);
}

static char		*set_width(char *str, unsigned int num, t_specifier *specifier)
{
	int len;

	len = ft_strlen(str);
	if (specifier->is_width && specifier->width < 0)
	{
		specifier->width *= -1;
		if ((specifier->flags & FLAG_MINUS) == 0)
			specifier->flags ^= FLAG_MINUS;
	}
	if (len >= specifier->width)
		return (str);
	if (specifier->flags & FLAG_MINUS)
		str = pad_right(' ', specifier->width - len, str, 1);
	else
	{
		if (specifier->flags & FLAG_ZERO && specifier->precision == -1)
		{
			str = pad_left('0', specifier->width - len, str, 1);
			if (num < 0)
			{
				str[0] = '-';
				str[specifier->width - len] = '0';
			}
		}
		else
			str = pad_left(' ', specifier->width - len, str, 1);
	}
	return (str);
}

void			print_x(va_list args, t_specifier *specifier, int *count)
{
	unsigned int	number;
	char			*str;
	int				len;

	number = (unsigned int)va_arg(args, unsigned int);
	if (!(str = get_hex_str(number, (specifier->specifier == 'X') ? 1 : 0)))
	{
		*count = -1;
		return ;
	}
	len = ft_strlen(str);
	str = set_precision(str, specifier->precision);
	if (specifier->precision == 0 && number == 0)
		str[--len] = '\0';
	str = set_width(str, number, specifier);
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
}
