/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:03:28 by ssummers          #+#    #+#             */
/*   Updated: 2020/05/28 23:41:37 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;

	ptr = (unsigned char*)b;
	while (len-- > 0)
		*(ptr++) = (unsigned char)c;
	return (b);
}
