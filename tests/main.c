/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 11:46:13 by asimoes           #+#    #+#             */
/*   Updated: 2020/06/21 12:08:43 by asimoes          ###   ########.fr       */
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
	
	printf("[                         DECIMAL                          ]\n");
	printf("---------------------------WIDTH----------------------------\n");
	/*printf("%-20s| %-20s| %-20s| %-20s\n", "TITLE", "SPECIFIER", "NUMBER", "RESULT");
	printf("%-20s| %-20s| %-20d| ", "Default width of 10", "%10d", 1337, 1337);
	ft_printf("%10d|\n", 1337);
	return (0);*/
	printf("%%10d 1337:\t\t |%10d|\n", 1337);
	ft_printf("%%10d 1337:\t\t |%10d|\n", 1337);
	printf("%%-10d 1337:\t\t |%-10d|\n", 1337);
	ft_printf("%%-10d 1337:\t\t |%-10d|\n", 1337);
	printf("%%+10d 1337:\t\t |%+10d|\n", 1337);
	ft_printf("%%+10d 1337:\t\t |%+10d|\n", 1337);
	printf("%% 10d 1337:\t\t |% 10d|\n", 1337);
	ft_printf("%% 10d 1337:\t\t |% 10d|\n", 1337);
	printf("%%010d 1337:\t\t |%010d|\n", 1337);
	ft_printf("%%010d 1337:\t\t |%010d|\n", 1337);
	printf("-------------------------DEFAULT---------------------------\n");
	printf("Default:\t\t\t\t |%d|\n", 1337);
	ft_printf("Default:\t\t\t\t |%d|\n", 1337);
	printf("Left-justify:\t\t\t\t |%-d|\n", 1337);
	ft_printf("Left-justify:\t\t\t\t |%-d|\n", 1337);
	printf("Preceed by sign:\t\t\t |%+d|\n", 1337);
	ft_printf("Preceed by sign:\t\t\t |%+d|\n", 1337);
	printf("Blank space if no sign:\t\t\t |% d|\n", 1337);
	ft_printf("Blank space if no sign:\t\t\t |% d|\n", 1337);
	printf("Blank space if no sign with zero flag:\t |%0 d|\n", 1337);
	ft_printf("Blank space if no sign with zero flag:\t |%0 d|\n", 1337);
	printf("Left pad zeroes:\t\t\t |%0d|\n", 1337);
	ft_printf("Left pad zeroes:\t\t\t |%0d|\n", 1337);
	printf("-------------------------PRECISION--------------------------\n");
	printf("Default:\t\t\t\t |%.15d|\n", 101214);
	ft_printf("Default:\t\t\t\t |%.15d|\n", 101214);
	printf("Left-justify:\t\t\t\t |%-.15d|\n", 101214);
	ft_printf("Left-justify:\t\t\t\t |%-.15d|\n", 101214);
	printf("Preceed by sign:\t\t\t |%+.15d|\n", 101214);
	ft_printf("Preceed by sign:\t\t\t |%+.15d|\n", 101214);
	printf("Blank space if no sign:\t\t\t |% .15d|\n", 101214);
	ft_printf("Blank space if no sign:\t\t\t |% .15d|\n", 101214);
	printf("Left pad zeroes:\t\t\t |%0.15d|\n", 101214);
	ft_printf("Left pad zeroes:\t\t\t |%0.15d|\n", 101214);
	printf("Precision zero:\t\t\t\t |%0.0d|\n", 0);
	ft_printf("Precision zero:\t\t\t\t |%0.0d|\n", 0);
	printf("---------------------PRECISION NEGATIVE---------------------\n");
	printf("Default:\t\t\t\t |%.15d|\n", -101214);
	ft_printf("Default:\t\t\t\t |%.15d|\n", -101214);
	printf("Left-justify:\t\t\t\t |%-.15d|\n", -101214);
	ft_printf("Left-justify:\t\t\t\t |%-.15d|\n", -101214);
	printf("Preceed by sign:\t\t\t |%+.15d|\n", -101214);
	ft_printf("Preceed by sign:\t\t\t |%+.15d|\n", -101214);
	printf("Blank space if no sign:\t\t\t |% .15d|\n", -101214);
	ft_printf("Blank space if no sign:\t\t\t |% .15d|\n", -101214);
	printf("Left pad zeroes:\t\t\t |%0.15d|\n", -101214);
	ft_printf("Left pad zeroes:\t\t\t |%0.15d|\n", -101214);
	printf("Precision zero:\t\t\t\t |%0.0d|\n", -0);
	ft_printf("Precision zero:\t\t\t\t |%0.0d|\n", -0);
	printf("----------------------SMALL PRECISION-----------------------\n");
	printf("Default:\t\t\t\t |%.3d|\n", 101214);
	ft_printf("Default:\t\t\t\t |%.3d|\n", 101214);
	printf("Left-justify:\t\t\t\t |%-.3d|\n", 101214);
	ft_printf("Left-justify:\t\t\t\t |%-.3d|\n", 101214);
	printf("Preceed by sign:\t\t\t |%+.3d|\n", 101214);
	ft_printf("Preceed by sign:\t\t\t |%+.3d|\n", 101214);
	printf("Blank space if no sign:\t\t\t |% .3d|\n", 101214);
	ft_printf("Blank space if no sign:\t\t\t |% .3d|\n", 101214);
	printf("Left pad zeroes:\t\t\t |%0.3d|\n", 101214);
	ft_printf("Left pad zeroes:\t\t\t |%0.3d|\n", 101214);
	printf("Precision zero:\t\t\t\t |%0.0d|\n", 0);
	ft_printf("Precision zero:\t\t\t\t |%0.0d|\n", 0);
	printf("---------------------WIDTH & PRECISION----------------------\n");
	printf("Default:\t\t\t\t |%25.15d|\n", 101214);
	ft_printf("Default:\t\t\t\t |%25.15d|\n", 101214);
	printf("Left-justify:\t\t\t\t |%-25.15d|\n", 101214);
	ft_printf("Left-justify:\t\t\t\t |%-25.15d|\n", 101214);
	printf("Preceed by sign:\t\t\t |%+25.15d|\n", 101214);
	ft_printf("Preceed by sign:\t\t\t |%+25.15d|\n", 101214);
	printf("Blank space if no sign:\t\t\t |% 25.15d|\n", 101214);
	ft_printf("Blank space if no sign:\t\t\t |% 25.15d|\n", 101214);
	printf("Left pad zeroes:\t\t\t |%025.15d|\n", 101214);
	ft_printf("Left pad zeroes:\t\t\t |%025.15d|\n", 101214);
	printf("Precision zero:\t\t\t\t |%025.0d|\n", 0);
	ft_printf("Precision zero:\t\t\t\t |%025.0d|\n", 0);
	
	printf("[                        CHARACTER                         ]\n");
	printf("---------------------------WIDTH----------------------------\n");
	printf("%%10c a:\t\t\t |%10c|\n", 'a');
	ft_printf("%%10c a:\t\t\t |%10c|\n", 'a');
	printf("%%-10c a:\t\t |%-10c|\n", 'a');
	ft_printf("%%-10c a:\t\t |%-10c|\n", 'a');
	printf("%%+10c a:\t\t |%+10c|\n", 'a');
	ft_printf("%%+10c a:\t\t |%+10c|\n", 'a');
	printf("%% 10c a:\t\t |% 10c|\n", 'a');
	ft_printf("%% 10c a:\t\t |% 10c|\n", 'a');
	printf("%%010c a:\t\t |%010c|\n", 'a');
	ft_printf("%%010c a:\t\t |%010c|\n", 'a');
	printf("-------------------------DEFAULT---------------------------\n");
	printf("Default:\t\t\t\t |%c|\n", 'a');
	ft_printf("Default:\t\t\t\t |%c|\n", 'a');
	printf("Left-justify:\t\t\t\t |%-c|\n", 'a');
	ft_printf("Left-justify:\t\t\t\t |%-c|\n", 'a');
	printf("Preceed by sign:\t\t\t |%+c|\n", 'a');
	ft_printf("Preceed by sign:\t\t\t |%+c|\n", 'a');
	printf("Blank space if no sign:\t\t\t |% c|\n", 'a');
	ft_printf("Blank space if no sign:\t\t\t |% c|\n", 'a');
	printf("Blank space if no sign with zero flag:\t |%0 c|\n", 'a');
	ft_printf("Blank space if no sign with zero flag:\t |%0 c|\n", 'a');
	printf("Left pad zeroes:\t\t\t |%0c|\n", 'a');
	ft_printf("Left pad zeroes:\t\t\t |%0c|\n", 'a');
	printf("-------------------------PRECISION--------------------------\n");
	printf("Default:\t\t\t\t |%.15c|\n", 'a');
	ft_printf("Default:\t\t\t\t |%.15c|\n", 'a');
	printf("Left-justify:\t\t\t\t |%-.15c|\n", 'a');
	ft_printf("Left-justify:\t\t\t\t |%-.15c|\n", 'a');
	printf("Preceed by sign:\t\t\t |%+.15c|\n", 'a');
	ft_printf("Preceed by sign:\t\t\t |%+.15c|\n", 'a');
	printf("Blank space if no sign:\t\t\t |% .15c|\n", 'a');
	ft_printf("Blank space if no sign:\t\t\t |% .15c|\n", 'a');
	printf("Left pad zeroes:\t\t\t |%0.15c|\n", 'a');
	ft_printf("Left pad zeroes:\t\t\t |%0.15c|\n", 'a');
	printf("Precision zero:\t\t\t\t |%0.0c|\n", 'a');
	ft_printf("Precision zero:\t\t\t\t |%0.0c|\n", 'a');
	printf("---------------------WIDTH & PRECISION----------------------\n");
	printf("Default:\t\t\t\t |%25.15c|\n", 'a');
	ft_printf("Default:\t\t\t\t |%25.15c|\n", 'a');
	printf("Left-justify:\t\t\t\t |%-25.15c|\n", 'a');
	ft_printf("Left-justify:\t\t\t\t |%-25.15c|\n", 'a');
	printf("Preceed by sign:\t\t\t |%+25.15c|\n", 'a');
	ft_printf("Preceed by sign:\t\t\t |%+25.15c|\n", 'a');
	printf("Blank space if no sign:\t\t\t |% 25.15c|\n", 'a');
	ft_printf("Blank space if no sign:\t\t\t |% 25.15c|\n", 'a');
	printf("Left pad zeroes:\t\t\t |%025.15c|\n", 'a');
	ft_printf("Left pad zeroes:\t\t\t |%025.15c|\n", 'a');
	printf("Precision zero:\t\t\t\t |%025.0c|\n", 'a');
	ft_printf("Precision zero:\t\t\t\t |%025.0c|\n", 'a');
	
	return (0);
}