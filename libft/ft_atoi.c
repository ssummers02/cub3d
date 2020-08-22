/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim <kim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 03:26:35 by kim               #+#    #+#             */
/*   Updated: 2020/05/03 05:23:18 by kim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		negative;
	int		i;
	long	n;

	i = 0;
	negative = 1;
	n = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
					*str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		if (n > (n * 10 + (str[i] - '0')))
			return (negative > 0 ? -1 : 0);
		n = n * 10 + (str[i++] - '0');
	}
	return (n * negative);
}
