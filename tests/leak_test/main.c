/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 13:19:03 by asimoes           #+#    #+#             */
/*   Updated: 2020/08/03 13:30:31 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../libft/libft.h"
#include "../../ft_printf.h"

int		main(void)
{
	int a = 25;
	char *b = "salut ça va";

	ft_printf("test de leak 1");
	ft_printf("test 2: %d\n", a);
	ft_printf("test 3: %s\n", b);
	ft_printf("test 4: %c\n", 'a');
	ft_printf("test 5: %p\n", b);
	ft_printf("test 6: %u\n", 879);
	ft_printf("test 7: %x\n", 10);
	ft_printf("test 8: %X\n", 10);
	
	while (1)
	{
		sleep(2);
	}
	return (0);
}
