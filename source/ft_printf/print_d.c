/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:59:50 by ssummers          #+#    #+#             */
/*   Updated: 2020/07/01 22:45:02 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

static t_tab	*negativity(t_tab *tab, intmax_t nbr)
{
	if (nbr >= 0)
	{
		if (tab->c_flags[1] == '+')
			tab->ch_plus = '+';
		else if (tab->c_flags[2] == ' ')
			tab->ch_plus = ' ';
		else
			tab->ch_plus = '\0';
	}
	return (tab);
}

static void		do_basic_d(t_tab *tab, intmax_t nbr)
{
	if (nbr == 0 && tab->prec == 0)
	{
		if (tab->ch_plus != '\0')
			tab->width--;
		if (tab->c_flags[0] != '-')
			print_sign(tab, tab->width, ' ');
		if (tab->c_flags[1] == '+')
			print_sign(tab, 1, '+');
		else if (tab->c_flags[2] == ' ')
			print_sign(tab, 1, ' ');
		if (tab->c_flags[0] == '-')
			print_sign(tab, tab->width, ' ');
	}
}

static void		do_d(t_tab *tab, int zeroes, int is_neg)
{
	if (tab->c_flags[0] != '-')
		print_sign(tab, tab->width - zeroes - tab->s_len, ' ');
	if (is_neg)
		write(1, "-", 1);
	if (tab->ch_plus != '\0')
		write(1, &tab->ch_plus, 1);
	print_sign(tab, zeroes, '0');
}

static int		get_zeroes(t_tab *tab, int is_neg)
{
	int			zeroes;

	zeroes = 0;
	if (tab->c_flags[4] == '0' && tab->c_flags[0] != '-')
	{
		if (tab->prec >= 0 && tab->prec >= tab->s_len)
			zeroes = tab->prec - tab->s_len;
		else if (tab->prec >= 0 && tab->prec < tab->s_len)
			zeroes = 0;
		else if (tab->prec == -1)
		{
			zeroes = tab->width - tab->s_len;
			zeroes -= is_neg ? 1 : 0;
			if (tab->c_flags[2] == ' ' && tab->c_flags[1] != '+' && !is_neg)
				zeroes -= 1;
		}
		if (tab->c_flags[1] == '+' && !is_neg && tab->prec == -1)
			zeroes -= 1;
	}
	else if (tab->c_flags[0] == '-' || tab->c_flags[4] != '0')
	{
		if (tab->prec > 0 && tab->prec > tab->s_len)
			zeroes = tab->prec - tab->s_len;
	}
	return (zeroes);
}

t_tab			*print_d(t_tab *tab)
{
	long long	nbr;
	int			zeroes;
	int			is_neg;

	nbr = get_d_nbr(tab);
	negativity(tab, nbr);
	if (nbr == 0 && tab->prec == 0)
	{
		do_basic_d(tab, nbr);
		return (tab);
	}
	is_neg = (nbr < 0) ? 1 : 0;
	tab->s_len = nbr == 0 ? 1 : ft_nbr_size(nbr);
	nbr *= (is_neg && nbr != (-9223372036854775807 - 1)) ? -1 : 1;
	zeroes = get_zeroes(tab, is_neg);
	tab->s_len += tab->ch_plus != '\0' || is_neg ? 1 : 0;
	do_d(tab, zeroes, is_neg);
	if (nbr == -9223372036854775807 - 1)
		nb_max(tab);
	else
		ft_putnbrmax(nbr);
	help_d(tab, zeroes);
	tab->len += tab->s_len;
	return (tab);
}
