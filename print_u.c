/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 07:41:21 by asimoes           #+#    #+#             */
/*   Updated: 2020/06/25 11:39:31 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

static void		leftcat(char *s, char c)
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

char			*ft_utoa(unsigned int n)
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
	if (n < 0)
		long_nb *= -1;
	while (long_nb > 0)
	{
		leftcat(nbr, (char)(long_nb % 10) + '0');
		long_nb /= 10;
	}
	if (n < 0)
		leftcat(nbr, '-');
	return (nbr);
}

void	print_u(va_list args, t_specifier *specifier, int *count)
{
	unsigned int	number;
	char			*number_str;

	number = (unsigned int)va_arg(args, unsigned int);
	number_str = ft_utoa(number);
	ft_putstr_fd(number_str, 1);
}