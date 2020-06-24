/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 11:32:06 by asimoes           #+#    #+#             */
/*   Updated: 2020/06/24 11:20:37 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

void	print_s(va_list args, t_specifier *specifier, int *count)
{
	char	*str;
	int		len;
	
	str = (char*)va_arg(args, char *);
	if (str == NULL)
	{
		if (!(str = malloc(7 * sizeof(char))))
		{
			*count = -1;
			return ;
		}
		ft_strlcpy(str, "(null)", 6);
	}
	len = ft_strlen(str);
	if (specifier->precision != -1 && specifier->precision < len)
	{
		str = ft_substr(str, 0, specifier->precision);
		len = specifier->precision;
	}
	if (specifier->flags & FLAG_MINUS && specifier->width > len)
		str = pad_right(' ', specifier->width - len, str);
	else if (specifier->width > len)
		str = pad_left(' ', specifier->width - len, str);
	*count += ft_strlen(str);
	ft_putstr_fd(str, 1);
}