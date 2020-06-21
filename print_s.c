/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 11:32:06 by asimoes           #+#    #+#             */
/*   Updated: 2020/06/22 01:08:59 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

void	print_s(va_list args, t_specifier *specifier, int *count)
{
	char	*str;
	
	str = (char*)va_arg(args, char *);
	*count += ft_strlen(str);
	ft_putstr_fd(str, 1);
}