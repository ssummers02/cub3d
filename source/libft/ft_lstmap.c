/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim <kim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:59:38 by kim               #+#    #+#             */
/*   Updated: 2020/05/07 01:23:04 by kim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*first;

	if (!lst)
		return (NULL);
	if (!(result = ft_lstnew(f(lst->content))))
		return (NULL);
	first = result;
	while (lst)
	{
		if (lst->next)
		{
			if (!(result->next = ft_lstnew(f(lst->next->content))))
			{
				ft_lstclear(&first, del);
				return (0);
			}
			result = result->next;
		}
		lst = lst->next;
	}
	result->next = NULL;
	return (first);
}
