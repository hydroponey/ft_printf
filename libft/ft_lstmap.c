/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes <asimoes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 22:20:33 by asimoes           #+#    #+#             */
/*   Updated: 2020/05/20 19:47:49 by asimoes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur;
	t_list	*new;
	t_list	*ret;
	void	*content;

	new = NULL;
	ret = NULL;
	if (lst != NULL && f != NULL)
	{
		cur = lst;
		while (cur)
		{
			if ((content = f(cur->content)))
			{
				if (!(new = ft_lstnew(content)))
				{
					ft_lstclear(&lst, del);
					return (NULL);
				}
				ft_lstadd_back(&ret, new);
			}
			cur = cur->next;
		}
	}
	return (ret);
}
