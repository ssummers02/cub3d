/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:59:50 by ssummers          #+#    #+#             */
/*   Updated: 2020/06/07 20:56:37 by kim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

t_tab		*print_pcent(t_tab *tab)
{
	if (tab->c_flags[4] == '0' && !tab->c_flags[0] && tab->prec <= 0)
	{
		tab->prec = tab->width;
		tab->width = 0;
	}
	if (tab->c_flags[0] != '-')
		print_sign(tab, tab->width - 1, ' ');
	if (tab->c_flags[4] == '0')
		print_sign(tab, tab->prec - 1, '0');
	write(1, "%", 1);
	if (tab->c_flags[0] == '-')
		print_sign(tab, tab->width - 1, ' ');
	tab->len += 1;
	return (tab);
}

void		print_other(t_tab *tab)
{
	if (tab->c_fmt[tab->i] == '%')
		print_pcent(tab);
	else
		print_sign(tab, tab->width - 1, ' ');
}

t_tab		*print_sign(t_tab *tab, int amount, int c)
{
	char	*buf;

	if (amount > 0)
	{
		if (!(buf = (char*)malloc(sizeof(char) * amount + 1)))
			exit(-1);
		ft_memset(buf, c, amount);
		write(1, buf, amount);
		tab->len += amount;
		free(buf);
	}
	return (tab);
}
