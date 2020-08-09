/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 22:25:08 by asimoes           #+#    #+#             */
/*   Updated: 2020/05/07 21:12:18 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *cur;

	if (!lst)
		return ;
	cur = lst;
	while (1)
	{
		f(cur->content);
		if (!cur->next)
			break ;
		cur = cur->next;
	}
}
