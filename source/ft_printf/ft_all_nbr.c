/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:53:37 by ssummers          #+#    #+#             */
/*   Updated: 2020/05/28 23:40:05 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

int				ft_nbr_size(intmax_t nbr)
{
	int			len;

	if (nbr < 0)
		nbr *= -1;
	len = 1;
	while ((nbr /= 10) > 0)
		len++;
	return (len);
}

int				ft_nbr_size_base(uintmax_t nbr, int base)
{
	int			len;

	len = 0;
	len += (nbr < 0);
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

long double		get_float(t_tab *tab)
{
	long double	nbr;

	if (ft_strcmp(tab->len_flags, "L") == 0)
		nbr = (long double)va_arg(tab->args, long double);
	else
		nbr = (double)va_arg(tab->args, double);
	return (nbr);
}

intmax_t		get_d_nbr(t_tab *tab)
{
	intmax_t	nbr;

	if (ft_strcmp(tab->len_flags, "h") == 0)
		nbr = (short)va_arg(tab->args, long long);
	else if (ft_strcmp(tab->len_flags, "hh") == 0)
		nbr = (signed char)va_arg(tab->args, long long);
	else if (ft_strcmp(tab->len_flags, "l") == 0)
		nbr = (long)va_arg(tab->args, long long int);
	else if (ft_strcmp(tab->len_flags, "ll") == 0)
		nbr = (long long)va_arg(tab->args, long long);
	else
		nbr = (int)va_arg(tab->args, int);
	return (nbr);
}

uintmax_t		get_oux_nbr(t_tab *tab)
{
	uintmax_t	nbr;

	if (ft_strcmp(tab->len_flags, "h") == 0)
		nbr = (unsigned short)va_arg(tab->args, unsigned int);
	else if (ft_strcmp(tab->len_flags, "hh") == 0)
		nbr = (unsigned char)va_arg(tab->args, unsigned int);
	else if (ft_strcmp(tab->len_flags, "l") == 0)
		nbr = (unsigned long)va_arg(tab->args, unsigned long int);
	else if (ft_strcmp(tab->len_flags, "ll") == 0)
		nbr = (unsigned long long)va_arg(tab->args, unsigned long long);
	else
		nbr = (unsigned int)va_arg(tab->args, unsigned int);
	nbr = (uintmax_t)nbr;
	return (nbr);
}
