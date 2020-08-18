/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:29:50 by ssummers          #+#    #+#             */
/*   Updated: 2020/05/28 23:41:36 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

int		ft_intlen_max(uintmax_t nbr)
{
	int len;

	if (nbr < 0)
		nbr *= -1;
	len = 1;
	while ((nbr /= 10) > 0)
		len++;
	return (len);
}
