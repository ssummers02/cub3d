/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:04:21 by ssummers          #+#    #+#             */
/*   Updated: 2020/05/28 23:41:38 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

char		*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char*)s;
	while (*str != '\0')
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == (char)c)
		return (str);
	return (NULL);
}
