/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:59:50 by ssummers          #+#    #+#             */
/*   Updated: 2020/05/28 23:41:45 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

static void		print_o_zero(t_tab *tab, uintmax_t nbr)
{
	if (tab->c_flags[3] == '#' && nbr)
		write(1, "0", 1);
}

static int		collect_o(t_tab *tab, uintmax_t nbr)
{
	int			n_blank;

	if (tab->c_flags[3] == '#' && nbr)
		tab->s_len++;
	n_blank = tab->s_len;
	if (tab->c_flags[4] == '0' && tab->prec == -1 && tab->c_flags[0] != '-')
		tab->prec = tab->width;
	else if (tab->c_flags[0] == '-' && tab->c_flags[4] == '0'\
		&& tab->prec == -1)
		tab->prec = tab->s_len;
	if (tab->s_len <= tab->prec && tab->prec > 0)
		n_blank = tab->prec;
	nbr += 0;
	return (n_blank);
}

t_tab			*print_o(t_tab *tab)
{
	char		*tmp;
	uintmax_t	nbr;
	int			n_blank;

	nbr = get_oux_nbr(tab);
	if (nbr == 0 && tab->prec == 0 && tab->c_flags[3] != '#')
	{
		print_sign(tab, tab->width, ' ');
		return (tab);
	}
	tmp = nbr == 0 ? ft_strdup("0") : ft_itoa_base(nbr, 8);
	tab->s_len = nbr == 0 ? 1 : ft_strlen(tmp);
	n_blank = collect_o(tab, nbr);
	if (tab->c_flags[0] != '-')
		print_sign(tab, tab->width - n_blank, ' ');
	print_o_zero(tab, nbr);
	print_sign(tab, tab->prec - tab->s_len, '0');
	ft_putstr(tmp);
	if (tab->c_flags[0] == '-')
		print_sign(tab, tab->width - n_blank, ' ');
	tab->len += tab->s_len;
	free(tmp);
	return (tab);
}
