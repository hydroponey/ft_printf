/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 11:32:06 by asimoes           #+#    #+#             */
/*   Updated: 2020/07/28 14:50:52 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

static char		*set_preci(char *str, t_specifier *s, int *len)
{
	char	*ptr;

	if (s->is_precision && s->precision < *len && s->precision >= 0)
	{
		ptr = str;
		str = ft_substr(str, 0, s->precision);
		*len = s->precision;
		free(ptr);
	}
	return (str);
}

static char		*set_width(char *str, t_specifier *s, int *len)
{
	char	c;

	c = (s->flags & FLAG_ZERO) ? '0' : ' ';
	if (s->flags & FLAG_MINUS && s->width > *len)
		str = pad_right(' ', s->width - *len, str, 1);
	else if (s->width > *len)
		str = pad_left(c, s->width - *len, str, 1);
	return (str);
}

void			print_s(va_list args, t_specifier *s, int *count)
{
	char		*str;
	char		*va_str;
	int			len;

	va_str = (char*)va_arg(args, char *);
	if (va_str == NULL)
	{
		if (!(str = malloc(7 * sizeof(char))))
		{
			*count = -1;
			return ;
		}
		ft_strlcpy(str, "(null)", 7);
	}
	else
		str = ft_strdup(va_str);
	len = ft_strlen(str);
	str = set_preci(str, s, &len);
	str = set_width(str, s, &len);
	*count += ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
}
