/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:31:36 by ssummers          #+#    #+#             */
/*   Updated: 2020/05/28 23:41:38 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

static int	ft_islower(int c)
{
	return (c >= 97 && c <= 122);
}

static int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}

static int	ft_isupper(int c)
{
	return (c >= 65 && c <= 90);
}

int			ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}

void		ft_s_toupper(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalpha(str[i]))
			ft_putchar(str[i]);
		else if (ft_isalpha(str[i]))
			ft_putchar(ft_toupper(str[i]));
		i++;
	}
}
