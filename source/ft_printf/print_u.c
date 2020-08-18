/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:59:50 by ssummers          #+#    #+#             */
/*   Updated: 2020/05/28 23:41:47 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

static void		print_u_zero(t_tab *tab, uintmax_t nbr)
{
	if (nbr && nbr == 0)
		print_sign(tab, 1, '0');
}

static int		collect_u(t_tab *tab)
{
	int			n_blank;

	n_blank = tab->s_len;
	if (tab->c_flags[4] == '0' && tab->prec == -1 && tab->c_flags[3] != '-')
		tab->prec = tab->width;
	if (tab->s_len <= tab->prec && tab->prec > 0)
		n_blank = tab->prec;
	if (tab->c_flags[0] != '-')
		print_sign(tab, tab->width - n_blank, ' ');
	return (n_blank);
}

t_tab			*print_u(t_tab *tab)
{
	char		*tmp;
	uintmax_t	nbr;
	int			n_blank;

	nbr = get_oux_nbr(tab);
	if (nbr == 0 && tab->prec == 0)
	{
		print_sign(tab, tab->width, ' ');
		return (tab);
	}
	if (nbr == 9223372036854775807)
		tmp = ft_strdup("9223372036854775807");
	else
		tmp = nbr == 0 ? ft_strdup("0") : ft_itoa_base(nbr, 10);
	tab->s_len = nbr == 0 ? 1 : ft_strlen(tmp);
	n_blank = collect_u(tab);
	print_u_zero(tab, nbr);
	print_sign(tab, tab->prec - tab->s_len, '0');
	ft_putstr(tmp);
	tab->len += ft_strlen(tmp);
	if (tab->c_flags[0] == '-')
		print_sign(tab, tab->width - n_blank, ' ');
	free(tmp);
	return (tab);
}
