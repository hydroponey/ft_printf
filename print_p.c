/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 07:41:21 by asimoes           #+#    #+#             */
/*   Updated: 2020/07/02 19:34:18 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"


char		*p_pad_left(char c, int n, char *data)
{
	char	padding[n + 1];
	char	*padded_string;

	ft_bzero(padding, n + 1);
	while (n--)
		padding[n] = c;
	padded_string = ft_strjoin(padding, data);
	free(data);
	return (padded_string);
}

char		*p_pad_right(char c, int n, char *data)
{
	char	padding[n + 1];
	char	*padded_string;

	ft_bzero(padding, n + 1);
	while (n--)
		padding[n] = c;
	padded_string = ft_strjoin(data, padding);
	free(data);
	return (padded_string);
}

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

char	*get_address_str(void *ptr)
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
	str = ft_strjoin("0x", str);
	return (str);
}

char	*p_set_width(char *str, t_specifier *specifier)
{
	int len;

	len = ft_strlen(str);
	if (specifier->is_width && specifier->width < 0)
	{
		specifier->width *= -1;
		if ((specifier->flags & FLAG_MINUS) == 0)
			specifier->flags ^= FLAG_MINUS;
	}
	if (len < specifier->width)
	{
		if (specifier->flags & FLAG_MINUS)
			str = p_pad_right(' ', specifier->width - len, str);
		else
			str = p_pad_left(' ', specifier->width - len, str);
	}
	return (str);
}

void	print_p(va_list args, t_specifier *specifier, int *count)
{
	char	*str;
	int		len;
	void	*ptr;

	ptr = (void*)va_arg(args, void*);
	if (ptr == NULL)
	{
		if (!(str = malloc(sizeof(char) * 4)))
		{
			*count = -1;
			return ;
		}
		ft_strlcpy(str, "0x0", 4);
	}
	else
	{
		str = get_address_str(ptr);
	}
	str = p_set_width(str, specifier);
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
}