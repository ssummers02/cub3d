/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:22:04 by ssummers          #+#    #+#             */
/*   Updated: 2020/05/28 23:41:41 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}

char	*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc((size + 1)));
}

char	*ft_strndup(char *str, int size)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = ft_strnew(size)))
		return (NULL);
	while (str && i < size)
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}
