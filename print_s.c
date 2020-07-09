/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 11:32:06 by asimoes           #+#    #+#             */
/*   Updated: 2020/07/09 14:15:17 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

void	print_s(va_list args, t_specifier *specifier, int *count)
{
	char		*str;
	char		*tmp;
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
	if (specifier->precision >= 0 && specifier->precision < len)
	{
		str = ft_substr(str, 0, specifier->precision);
		len = specifier->precision;
	}
	if (specifier->flags & FLAG_MINUS && specifier->width > len)
	{
		tmp = (free_ptr) ? str : NULL;
		str = pad_right(' ', specifier->width - len, str, 0);
		free(tmp);
	}
	else if (specifier->width > len)
	{
		tmp = (free_ptr) ? str : NULL;
		str = pad_left(' ', specifier->width - len, str, 0);
		free(tmp);
	}
	*count += ft_strlen(str);
	ft_putstr_fd(str, 1);
}
