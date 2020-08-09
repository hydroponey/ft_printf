/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:21:10 by asimoes           #+#    #+#             */
/*   Updated: 2020/05/14 11:15:33 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char					*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed;
	const char		*end;
	size_t			len;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
	{
		if (!(trimmed = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		trimmed[0] = '\0';
		return (trimmed);
	}
	while (*s1 != '\0' && is_in_set(*s1, set))
		s1++;
	len = ft_strlen(s1);
	end = s1 + len;
	while (len > 0 && is_in_set(s1[len-- - 1], set))
		end = s1 + len;
	len = (end < s1) ? 1 : end - s1 + 1;
	if (!(trimmed = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ft_strlcpy(trimmed, s1, len);
	return (trimmed);
}
