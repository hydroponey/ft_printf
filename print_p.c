/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 07:41:21 by asimoes           #+#    #+#             */
/*   Updated: 2020/08/11 21:15:22 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

static char		*get_address_str(void *ptr)
{
	char			*str;
	char			*old_ptr;
	unsigned long	ptr_value;
	char			cur[2];
	int				temp;

	ptr_value = (unsigned long)ptr;
	if (!(str = malloc(1)))
		return (NULL);
	str[0] = '\0';
	while (ptr_value != 0)
	{
		temp = ptr_value % 16;
		cur[0] = (temp < 10) ? temp + 48 : temp + 87;
		cur[1] = '\0';
		old_ptr = str;
		if (!(str = ft_strjoin(cur, str)))
		{
			free(old_ptr);
			return (NULL);
		}
		free(old_ptr);
		ptr_value = ptr_value / 16;
	}
	return (str);
}

static char		*set_precision(char *str, void *ptr, t_s_data *specifier)
{
	int len;

	len = ft_strlen(str);
	if (specifier->is_precision)
	{
		if (ptr == NULL && specifier->precision == 0)
		{
			str[0] = '\0';
			return (str);
		}
		if (specifier->precision > len)
			str = pad_left('0', specifier->precision - len, str);
	}
	return (str);
}

static char		*set_width(char *str, t_s_data *specifier)
{
	int len;

	len = ft_strlen(str);
	if (specifier->is_width && len < specifier->width)
	{
		if (specifier->flags & FLAG_MINUS)
			str = pad_right(' ', specifier->width - len, str);
		else
			str = pad_left(' ', specifier->width - len, str);
	}
	return (str);
}

char			*get_str(void *ptr, int *count)
{
	char	*str;

	if (ptr == NULL)
	{
		if (!(str = malloc(sizeof(char) * 2)))
		{
			*count = -1;
			return (str);
		}
		ft_strlcpy(str, "0", 2);
	}
	else
	{
		if (!(str = get_address_str(ptr)))
		{
			*count = -1;
			return (str);
		}
	}
	return (str);
}

void			print_p(va_list args, t_s_data *specifier, int *count)
{
	char	*str;
	char	*old_ptr;
	void	*ptr;

	ptr = (void*)va_arg(args, void*);
	if (!(str = get_str(ptr, count)))
		return ;
	str = set_precision(str, ptr, specifier);
	old_ptr = str;
	if (!(str = ft_strjoin("0x", str)))
	{
		*count = -1;
		return ;
	}
	free(old_ptr);
	str = set_width(str, specifier);
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}
