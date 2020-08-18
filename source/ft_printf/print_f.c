/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:59:50 by ssummers          #+#    #+#             */
/*   Updated: 2020/07/01 22:48:50 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

static void			do_f(long double nbr, t_tab *tab, int not_blank,\
					int zeroes)
{
	if (!tab->c_flags[0] && !tab->c_flags[4])
		print_sign(tab, tab->width - not_blank, ' ');
	if (tab->c_flags[2] == ' ' && nbr >= 0 && tab->width)
		print_sign(tab, 1, ' ');
	if (nbr < 0)
		print_sign(tab, 1, '-');
	if (nbr >= 0 && tab->c_flags[1] == '+')
		print_sign(tab, 1, '+');
	if (tab->c_flags[4] == '0' && zeroes >= 1)
		print_sign(tab, zeroes, '0');
}

static int			collect_f(t_tab *tab, long double nbr, int not_blank)
{
	if (tab->prec == 0 && tab->c_flags[3] == '#')
		not_blank++;
	if (tab->c_flags[2] == ' ' && nbr >= 0)
		not_blank++;
	if (nbr < 0 || (tab->c_flags[1] == '+' && nbr >= 0))
		not_blank++;
	return (not_blank);
}

void				help_d(t_tab *tab, int zeroes)
{
	if (tab->c_flags[0] == '-')
		print_sign(tab, tab->width - zeroes - tab->s_len, ' ');
	if (tab->width < 0)
		print_sign(tab, tab->width * (-1) - tab->s_len, ' ');
}

t_tab				*print_f(t_tab *tab)
{
	long double		nbr;
	char			*flt;
	int				not_blank;
	int				zeroes;

	zeroes = 0;
	nbr = get_float(tab);
	nbr < 0 ? tab->len-- : tab->len;
	flt = ft_ftoa(nbr, tab->prec, '.');
	not_blank = ft_strlen(flt);
	not_blank = collect_f(tab, nbr, not_blank);
	if (!tab->c_flags[0] && tab->width > tab->prec && tab->width > not_blank)
		zeroes = tab->width - not_blank;
	do_f(nbr, tab, not_blank, zeroes);
	ft_putstr(flt);
	if (tab->c_flags[3] && tab->prec == 0)
		print_sign(tab, 1, '.');
	if (tab->c_flags[0] == '-')
		print_sign(tab, tab->width - not_blank, ' ');
	tab->len += not_blank;
	free(flt);
	return (tab);
}
