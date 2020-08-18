/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim <kim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:58:58 by kim               #+#    #+#             */
/*   Updated: 2020/05/02 00:02:11 by kim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*next;

	if (!(list = *lst))
		return ;
	while (list)
	{
		next = list->next;
		del(list->content);
		free(list);
		list = next;
	}
	*lst = NULL;
}
