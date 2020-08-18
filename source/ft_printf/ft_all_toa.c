/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_toa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 23:40:06 by ssummers          #+#    #+#             */
/*   Updated: 2020/05/28 23:40:13 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

char					*ft_itoa_base(uintmax_t nbr, int base)
{
	char				*new;
	int					j;

	j = ft_nbr_size_base(nbr, base);
	if (!(new = (char *)malloc(sizeof(char) * j + 1)))
		return (NULL);
	if (nbr < 0)
		new[0] = '-';
	new[j] = '\0';
	while (j--)
	{
		new[j] = (nbr % base < 10) ? nbr % base + '0' : nbr % base + 'a' - 10;
		nbr /= base;
	}
	return (new);
}

static long double		rounding(long double nbr, int prec)
{
	long double			rounding;
	int					i;

	i = 0;
	rounding = 0.5;
	if (nbr < 0)
		rounding *= -1;
	while (i++ < prec)
		rounding /= 10.0;
	return (rounding);
}

static char				*joining(char *whole, char *dec_part)
{
	char			*joint;

	joint = ft_strjoin(whole, dec_part);
	free(whole);
	free(dec_part);
	return (joint);
}

char					*ft_ftoa(long double nbr, int prec, char dot)
{
	char				*joint;
	char				*whole;
	char				*dec_part;
	unsigned long long	dec;
	int					i;

	i = 0;
	prec = prec == -1 ? 6 : prec;
	nbr += prec >= 0 ? rounding(nbr, prec) : 0;
	nbr < 0 ? nbr *= -1 : nbr * 1;
	whole = ft_itoa_uintmax(nbr);
	dec = nbr;
	nbr = prec > 0 ? nbr - dec : 0;
	dec_part = ft_strnew(prec + 1);
	dec_part[i++] = (dot && prec > 0) ? '.' : '\0';
	while (prec-- > 0)
	{
		nbr *= 10;
		dec = nbr;
		nbr -= dec;
		dec_part[i++] = dec + '0';
	}
	joint = joining(whole, dec_part);
	return (joint);
}

char					*ft_itoa_uintmax(uintmax_t n)
{
	char				*new;
	int					len;

	len = ft_intlen_max(n) + 1;
	if (!(new = ft_strnew(len + 1)))
		return (NULL);
	new[len] = '\0';
	len--;
	while (n >= 10)
	{
		new[--len] = (char)(n % 10 + '0');
		n /= 10;
	}
	new[--len] = (char)(n + '0');
	return (new);
}
