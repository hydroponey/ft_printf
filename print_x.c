/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 07:41:21 by asimoes           #+#    #+#             */
/*   Updated: 2020/07/03 11:48:05 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

char	*get_hex_str(unsigned int number, short int capitalize)
{
	char			*str;
	int				i;
	char			cur[2];
	int				temp;

	capitalize = (capitalize) ? 55 : 87;
	str = malloc(1);
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

void	print_x(va_list args, t_specifier *specifier, int *count)
{
	unsigned int	number;
	char			*str;

	number = (unsigned int)va_arg(args, unsigned int);
	str = get_hex_str(number, (specifier->specifier == 'X') ? 1 : 0);
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
}