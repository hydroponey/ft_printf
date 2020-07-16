/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 07:41:21 by asimoes           #+#    #+#             */
/*   Updated: 2020/07/16 22:30:26 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

void		print_nulchar(t_specifier *specifier, int *count)
{
	if (specifier->is_width && (specifier->flags & FLAG_MINUS) == 0)
	{
		while (--specifier->width)
		{
			ft_putchar(' ');
			(*count)++;
		}
	}
	ft_putchar((char)0);
	(*count)++;
	if (specifier->is_width && specifier->flags & FLAG_MINUS)
	{
		while (--specifier->width && (*count)++)
			ft_putchar(' ');
	}
}

void		print_c(va_list args, t_specifier *s, int *count)
{
	char	*str;
	int		c;

	c = (s->character != -1) ? s->character : (int)va_arg(args, int);
	if (c == 0)
	{
		print_nulchar(s, count);
		return ;
	}
	if (!(str = malloc(2 * sizeof(char))))
	{
		*count = -1;
		return ;
	}
	str[0] = (char)c;
	str[1] = '\0';
	if (s->width > 1 && s->flags & FLAG_MINUS)
		str = pad_right(' ', s->width - 1, str, 1);
	else if (s->width > 1)
		str = pad_left(s->flags & FLAG_ZERO ? '0' : ' ', s->width - 1, str, 1);
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}
