/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 07:41:21 by asimoes           #+#    #+#             */
/*   Updated: 2020/06/21 12:07:35 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

void		print_c(va_list args, t_specifier *specifier, int *count)
{
	char	*str;
	int		c;

	c = (int)va_arg(args, int);
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
			str = pad_left(' ', specifier->width - 1, str);
	}
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}