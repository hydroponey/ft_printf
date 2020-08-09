/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 21:53:33 by asimoes           #+#    #+#             */
/*   Updated: 2020/05/07 21:33:27 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s1);
	if (!(dup = malloc((len + 1) * sizeof(char))))
		return (NULL);
	len = 0;
	while (s1[len])
	{
		dup[len] = s1[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}
