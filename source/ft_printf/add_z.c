/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:54:31 by ssummers          #+#    #+#             */
/*   Updated: 2020/05/28 23:40:01 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

t_tab	*add_z(t_tab *tab, int m_z, int mod, uintmax_t nbr)
{
	int i;

	i = tab->prec;
	if (!nbr)
		tab->padding = tab->width - tab->s_len - m_z;
	else if (tab->c_flags[4] != '0' && i == -1)
		tab->padding = tab->width - tab->s_len - mod;
	else if (tab->c_flags[4] == '0' && i != -1 && i < tab->s_len)
		tab->padding = tab->width - tab->s_len - mod;
	else if (tab->c_flags[4] != '0' && tab->prec != -1)
		tab->padding = tab->width - tab->s_len - mod - m_z;
	else if (tab->c_flags[4] == '0' && i && i > tab->s_len)
		tab->padding = tab->width - i - mod;
	else if (tab->c_flags[4] == '0' && tab->c_flags[0] == '-'\
			&& tab->prec == -1)
		tab->padding = tab->width - tab->s_len - mod - m_z;
	else
		tab->padding = 0;
	return (tab);
}
