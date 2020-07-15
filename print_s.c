/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 11:32:06 by asimoes           #+#    #+#             */
/*   Updated: 2020/07/15 14:16:00 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

/*
static char		*set_preci(char *str, t_specifier *s, int *len, short int fptr)
{
	char	*ptr;

	if (s->is_precision && s->precision < *len && s->precision >= 0)
	{
		ptr = (fptr) ? str : NULL;
		str = ft_substr(str, 0, s->precision);
		*len = s->precision;
		free(ptr);
	}
	return (str);
}*/

static char		*set_width(char *str, t_specifier *s, int *len, short int fptr)
{
	char	*ptr;
	char	c;

	c = (s->flags & FLAG_ZERO) ? '0' : ' ';
	ptr = (fptr) ? str : NULL;
	if (s->flags & FLAG_MINUS && s->width > *len)
		str = pad_right(' ', s->width - *len, str, 0);
	else if (s->width > *len)
		str = pad_left(c, s->width - *len, str, 0);
	free(ptr);
	return (str);
}

void			print_s(va_list args, t_specifier *s, int *count)
{
	char		*str;
	int			len;
	short int	free_ptr;

	free_ptr = 0;
	str = (char*)va_arg(args, char *);
	if (str == NULL)
	{
		if (!(str = malloc(7 * sizeof(char))))
		{
			*count = -1;
			return ;
		}
		free_ptr = 1;
		ft_strlcpy(str, "(null)", 7);
	}
	len = ft_strlen(str);
	//str = set_preci(str, s, &len, free_ptr);
	str = set_width(str, s, &len, free_ptr);
	*count += ft_strlen(str);
	ft_putstr_fd(str, 1);
}
