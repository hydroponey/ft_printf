/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 04:06:50 by asimoes           #+#    #+#             */
/*   Updated: 2020/05/19 18:47:37 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*ft_strndup(const char *str, unsigned int n)
{
	unsigned int	len;
	unsigned int	max;
	char			*copy;
	unsigned int	i;

	len = ft_strlen(str);
	max = (len < n) ? len : n;
	if (!(copy = (char *)malloc(sizeof(char) * (max + 1))))
		return (NULL);
	i = 0;
	while (i < max)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static void				ft_freetab(char **tab)
{
	while (*tab)
		free(*tab++);
	free(tab);
}

static int				get_elem_count(const char *s, char c)
{
	int			count;
	const char	*end;

	count = 0;
	end = NULL;
	while (*s)
	{
		if (*s != c)
		{
			end = ft_strchr(s, c);
			count++;
			if (!end || c == '\0')
				break ;
			s = end;
		}
		s++;
	}
	return (count);
}

char					**ft_split(char const *s, char c)
{
	char			**tab;
	const char		*end;
	unsigned int	i;

	if (!s || !(tab = malloc(sizeof(char *) * (get_elem_count(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			end = ft_strchr(s, c);
			if (!(tab[i++] = ft_strndup(s, (!end) ? ft_strlen(s) : (end - s))))
			{
				ft_freetab(tab);
				return (NULL);
			}
			if (!end || c == '\0')
				break ;
			s = end;
		}
		s++;
	}
	tab[i] = NULL;
	return (tab);
}
