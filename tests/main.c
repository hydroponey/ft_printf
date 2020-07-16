/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 11:46:13 by asimoes           #+#    #+#             */
/*   Updated: 2020/07/16 11:37:37 by asimoes          ###   ########.fr       */
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
	int	real;
	int mine;

	// % tests
	printf("printf: |");
	real = printf("%04.3%");
	printf("|\n");
	ft_printf("ft_printf: |");
	mine = ft_printf("%04.3%");
	ft_printf("|\n");
	printf("printf: %d | ft_printf: %d\n", real, mine);
	// ----------------------------------------------------------
	printf("printf: |");
	real = printf("%04.4%");
	printf("|\n");
	ft_printf("ft_printf: |");
	mine = ft_printf("%04.4%");
	ft_printf("|\n");
	printf("printf: %d | ft_printf: %d\n", real, mine);
	// ----------------------------------------------------------
	printf("printf: |");
	real = printf("%04%");
	printf("|\n");
	ft_printf("ft_printf: |");
	mine = ft_printf("%04%");
	ft_printf("|\n");
	printf("printf: %d | ft_printf: %d\n", real, mine);
	// ----------------------------------------------------------
	printf("printf: |");
	real = printf("%--4.%");
	printf("|\n");
	ft_printf("ft_printf: |");
	mine = ft_printf("%--4.%");
	ft_printf("|\n");
	printf("printf: %d | ft_printf: %d\n", real, mine);
	// ----------------------------------------------------------
	printf("printf: |");
	real = printf("%--4.*%", -4);
	printf("|\n");
	ft_printf("ft_printf: |");
	mine = ft_printf("%--4.*%", -4);
	ft_printf("|\n");
	printf("printf: %d | ft_printf: %d\n", real, mine);
	// ----------------------------------------------------------
	printf("printf: |");
	real = printf("%%");
	printf("|\n");
	ft_printf("ft_printf: |");
	mine = ft_printf("%%");
	ft_printf("|\n");
	printf("printf: %d | ft_printf: %d\n", real, mine);
	// ----------------------------------------------------------
	printf("printf: |");
	real = printf("%5%");
	printf("|\n");
	ft_printf("ft_printf: |");
	mine = ft_printf("%5%");
	ft_printf("|\n");
	printf("printf: %d | ft_printf: %d\n", real, mine);
	// ----------------------------------------------------------
	printf("printf: |");
	real = printf("%-5%");
	printf("|\n");
	ft_printf("ft_printf: |");
	mine = ft_printf("%-5%");
	ft_printf("|\n");
	printf("printf: %d | ft_printf: %d\n", real, mine);
	// ----------------------------------------------------------
	printf("printf: |");
	real = printf("%05%");
	printf("|\n");
	ft_printf("ft_printf: |");
	mine = ft_printf("%05%");
	ft_printf("|\n");
	printf("printf: %d | ft_printf: %d\n", real, mine);
	// ----------------------------------------------------------
	printf("printf: |");
	real = printf("%-05%");
	printf("|\n");
	ft_printf("ft_printf: |");
	mine = ft_printf("%-05%");
	ft_printf("|\n");
	printf("printf: %d | ft_printf: %d\n", real, mine);
	// ----------------------------------------------------------

	//
	/*printf("|%--2.4%|");
	ft_printf(" - |%--2.4%|\n");
	printf("|%--2%|");
	ft_printf(" - |%--2%|\n");
	printf("|%--1.%|");
	ft_printf(" - |%--1.%|\n");
	printf("|%--1.*%|", -4);
	ft_printf(" - |%--1.*%|\n", -4);
	printf("|%--1.*%|", -3);
	ft_printf(" - |%--1.*%|\n", -3);*/
	return (0);
}