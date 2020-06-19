/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 11:46:13 by asimoes           #+#    #+#             */
/*   Updated: 2020/06/19 17:32:05 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../ft_printf.h"

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

void print_address_hex(void* p0) {
    int i;
    uintptr_t p = (uintptr_t)p0;
	int leading_zero = 1;

    write_char('0'); write_char('x');
    for(i = (sizeof(p) << 3) - 4; i>=0; i -= 4) {
		if (leading_zero && (hex_digit((p >> i) & 0xf)) == '0')
			continue;
		else
			leading_zero = 0;
        write_char(hex_digit((p >> i) & 0xf));
    }
}

int main()
{
	printf("%#X\n", 15);
	ft_printf("%#X\n", 15);
	return (0);
}