/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:59:50 by ssummers          #+#    #+#             */
/*   Updated: 2020/07/01 22:47:06 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

static int		do_p(t_tab *tab)
{
	int			zeroes;

	zeroes = 0;
	if (tab->c_flags[4] != '0')
	{
		if (tab->prec > 0 && tab->prec > tab->s_len)
			zeroes = tab->prec - tab->s_len;
		else if (tab->prec == -1 && tab->width > tab->s_len)
			zeroes = 0;
	}
	else if (tab->c_flags[4] == '0')
	{
		if (tab->width > tab->s_len && tab->prec == -1)
			zeroes = tab->width - tab->s_len - 2;
		else if (tab->width > tab->s_len && tab->prec > 0)
			zeroes = tab->prec - tab->s_len;
	}
	return (zeroes);
}

static t_tab	*handle_str(t_tab *tab, char *tmp)
{
	if (tab->prec == 0)
	{
		ft_putstr("\0");
		tab->len--;
	}
	else
		ft_putstr(tmp);
	return (tab);
}

t_tab			*print_p(t_tab *tab)
{
	char		*tmp;
	uintmax_t	nbr;
	int			zeroes;

	nbr = (unsigned long)va_arg(tab->args, unsigned long int);
	nbr = (uintmax_t)nbr;
	tmp = nbr == 0 ? ft_strdup("0") : ft_itoa_base(nbr, 16);
	tab->s_len = ft_strlen(tmp);
	zeroes = do_p(tab);
	if (tab->prec == 0 && nbr == 0 && tab->width > 2)
		print_sign(tab, 1, ' ');
	if (tab->c_flags[0] != '-')
		print_sign(tab, tab->width - tab->s_len - zeroes - 2, ' ');
	write(1, "0x", 2);
	print_sign(tab, zeroes, '0');
	tab->len += 2;
	handle_str(tab, tmp);
	tab->len += tab->s_len;
	if (tab->c_flags[0] == '-')
		print_sign(tab, tab->width - tab->s_len - zeroes - 2, ' ');
	free(tmp);
	return (tab);
}
