/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 07:41:21 by asimoes           #+#    #+#             */
/*   Updated: 2020/06/25 03:14:02 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

void write_char(char c)
{
	write(1, &c, 1);
}

char hex_digit(int v) {
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'a' + v - 10; // <-- Here
}

int		print_address_hex(void* p0) {
    int 			i;
    unsigned long 	p;
	int 			leading_zero;
	short int		count;

	p = (unsigned long)p0;
	leading_zero = 1;
	count = 2;
    write_char('0');
	write_char('x');
    for(i = (sizeof(p) << 3) - 4; i>=0; i -= 4) {
		if (leading_zero && (hex_digit((p >> i) & 0xf)) == '0')
			continue;
		else
			leading_zero = 0;
        write_char(hex_digit((p >> i) & 0xf));
		count++;
    }
	return (count);
}

void	print_p(va_list args, t_specifier *specifier, int *count)
{
	void	*ptr;

	ptr = (void*)va_arg(args, void*);
	if (ptr == NULL)
	{
		ft_putstr_fd("(null)", 6);
		*count += 6;
	}
	else
	{
		*count += print_address_hex(ptr);
	}
}