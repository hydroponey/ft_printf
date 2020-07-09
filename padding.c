/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 11:42:59 by asimoes           #+#    #+#             */
/*   Updated: 2020/07/08 20:51:16 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

char	*pad_left(char c, int n, char *data, short int bFree)
{
	char	padding[n + 1];
	char	*padded_string;

	ft_bzero(padding, n + 1);
	while (n--)
		padding[n] = c;
	padded_string = ft_strjoin(padding, data);
	if (bFree)
		free(data);
	return (padded_string);
}

char	*pad_right(char c, int n, char *data, short int bFree)
{
	char	padding[n + 1];
	char	*padded_string;

	ft_bzero(padding, n + 1);
	while (n--)
		padding[n] = c;
	padded_string = ft_strjoin(data, padding);
	if (bFree)
		free(data);
	return (padded_string);
}
