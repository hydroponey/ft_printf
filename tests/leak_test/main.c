/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 13:19:03 by asimoes           #+#    #+#             */
/*   Updated: 2020/08/03 13:20:41 by asimoes          ###   ########.fr       */
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
	
	while (1)
	{
		sleep(2);
	}
	return (0);
}
