/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 07:41:21 by asimoes           #+#    #+#             */
/*   Updated: 2020/07/20 15:33:37 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

char		*get_address_str(void *ptr)
{
	char			*str;
	unsigned long	p0;
	char			cur[2];
	int				temp;

	p0 = (unsigned long)ptr;
	str = malloc(1);
	str[0] = '\0';
	while (p0 != 0)
	{
		temp = p0 % 16;
		cur[0] = (temp < 10) ? temp + 48 : temp + 87;
		cur[1] = '\0';
		str = ft_strjoin(cur, str);
		p0 = p0 / 16;
	}
	return (str);
}

char		*p_set_precision(char *str, void *ptr, t_specifier *specifier)
{
	int len;

	len = ft_strlen(str);
	if (specifier->is_precision)
	{
		if (ptr == NULL && specifier->precision == 0)
		{
			str[0] = '\0';
			return (str);
		}
		if (specifier->precision > len)
			str = pad_left('0', specifier->precision - len, str, 1);
	}
	return (str);
}

char		*p_set_width(char *str, t_specifier *specifier)
{
	int len;

	len = ft_strlen(str);
	/*if (specifier->is_width && specifier->width < 0)
	{
		specifier->width *= -1;
		if ((specifier->flags & FLAG_MINUS) == 0)
			specifier->flags ^= FLAG_MINUS;
	}*/
	if (specifier->is_width && len < specifier->width)
	{
		if (specifier->flags & FLAG_MINUS)
			str = pad_right(' ', specifier->width - len, str, 1);
		else
			str = pad_left(' ', specifier->width - len, str, 1);
	}
	return (str);
}

void		print_p(va_list args, t_specifier *specifier, int *count)
{
	char	*str;
	void	*ptr;

	ptr = (void*)va_arg(args, void*);
	if (ptr == NULL)
	{
		if (!(str = malloc(sizeof(char) * 2)))
		{
			*count = -1;
			return ;
		}
		ft_strlcpy(str, "0", 2);
	}
	else
	{
		str = get_address_str(ptr);
	}
	str = p_set_precision(str, ptr, specifier);
	str = ft_strjoin("0x", str);
	str = p_set_width(str, specifier);
	ft_putstr_fd(str, 1);
	printf("\n\tspecifier->is_width: %d\n\tlen: %d\n\tspecifier->width: %d\n\tFLAG_MINUS: %d\n", specifier->is_width, len, specifier->width, specifier->flags & FLAG_MINUS);
	*count += ft_strlen(str);
}
