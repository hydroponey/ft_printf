/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 07:41:21 by asimoes           #+#    #+#             */
/*   Updated: 2020/07/15 11:25:54 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

static void			leftcat(char *s, char c)
{
	int	len;

	len = ft_strlen(s);
	while (len)
	{
		s[len] = s[len - 1];
		len--;
	}
	s[0] = c;
}

static char			*ft_utoa(unsigned int n)
{
	char			*nbr;
	unsigned long	long_nb;

	if (!(nbr = malloc(sizeof(char) * 12)))
		return (NULL);
	ft_memset(nbr, 0, 12);
	long_nb = n;
	if (long_nb == 0)
	{
		nbr[0] = '0';
		nbr[1] = '\0';
		return (nbr);
	}
	while (long_nb > 0)
	{
		leftcat(nbr, (char)(long_nb % 10) + '0');
		long_nb /= 10;
	}
	return (nbr);
}

static char			*set_precision(char *num_str, int precision, int *len)
{
	char	*newstr;

	newstr = num_str;
	if (precision != -1 && precision > *len)
	{
		newstr = pad_left('0', precision - *len, num_str, 1);
		*len = ft_strlen(newstr);
	}
	return (newstr);
}

static char			*set_width(char *str, t_specifier *specifier, int *len)
{
	if (specifier->is_width && specifier->width < 0)
	{
		specifier->width *= -1;
		if ((specifier->flags & FLAG_MINUS) == 0)
			specifier->flags ^= FLAG_MINUS;
	}
	if (*len < specifier->width)
	{
		if (specifier->flags & FLAG_MINUS)
			str = pad_right(' ', specifier->width - *len, str, 1);
		else
		{
			if (specifier->flags & FLAG_ZERO && specifier->precision == -1)
				str = pad_left('0', specifier->width - *len, str, 1);
			else
				str = pad_left(' ', specifier->width - *len, str, 1);
		}
	}
	return (str);
}

void				print_u(va_list args, t_specifier *specifier, int *count)
{
	unsigned int		number;
	char				*number_str;
	int					len;

	number = (unsigned int)va_arg(args, unsigned int);
	if (!(number_str = ft_utoa(number)))
	{
		*count = -1;
		return ;
	}
	len = ft_strlen(number_str);
	number_str = set_precision(number_str, specifier->precision, &len);
	if (specifier->flags & FLAG_PLUS && number > 0)
	{
		number_str = pad_left('+', 1, number_str, 1);
		len++;
	}
	if (specifier->precision == 0 && number == 0)
		number_str[--len] = '\0';
	number_str = set_width(number_str, specifier, &len);
	if (number > 0 && len > specifier->width && specifier->flags & FLAG_SPACE)
		number_str = pad_left(' ', 1, number_str, 1);
	ft_putstr_fd(number_str, 1);
	*count += ft_strlen(number_str);
	free(number_str);
}
