/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 11:46:13 by asimoes           #+#    #+#             */
/*   Updated: 2020/07/08 17:35:00 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../libft/libft.h"
#include "../ft_printf.h"

char	*t_get_address_str(void *ptr)
{
	char			*str;
	int				i;
	unsigned long	p0;
	char			cur[2];
	int				temp;
	
	p0 = (unsigned long)ptr;
	str = malloc(1);
	str[0] = '\0';
	i = 0;
	while (p0 != 0)
	{
		temp = p0 % 16;
		if (temp < 10)
		{
			cur[0] = temp + 48;
			cur[1] = '\0';
			str = ft_strjoin(cur, str);
		}
		else
		{
			cur[0] = temp + 87;
			cur[1] = '\0';
			str = ft_strjoin(cur, str);
		}
		p0 = p0/16;
	}
	return (str);
}

int main()
{
	char	*ptr = "salut ça va";
	/*printf("[                         DECIMAL                          ]\n");
	printf("---------------------------WIDTH----------------------------\n");
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
	printf("Width 10 Precision 5:\t\t\t\t |%10.5d|\n", -216);
	ft_printf("Width 10 Precision 5:\t\t\t\t |%10.5d|\n", -216);
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
	printf("---------------------------POINTER--------------------------\n");
	printf("Pointer: %p\n", ptr);
	ft_printf("Pointer: %p\n", ptr);*/
	
	printf("|%5c|\n", '\0');
	ft_printf("|%5c|\n", '\0');
	
	return (0);
}