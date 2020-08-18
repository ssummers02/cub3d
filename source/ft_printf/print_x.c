/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:59:50 by ssummers          #+#    #+#             */
/*   Updated: 2020/05/28 23:41:34 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

static t_tab	*print_zero(t_tab *tab, char spec, uintmax_t nbr)
{
	if (nbr && tab->c_flags[3] == '#')
	{
		if (spec == 'X')
		{
			write(1, "0X", 2);
			tab->len += 2;
		}
		else if (spec == 'x')
		{
			write(1, "0x", 2);
			tab->len += 2;
		}
	}
	return (tab);
}

static char		*do_x(t_tab *tab, uintmax_t nbr, int m_z, char *tmp)
{
	if (tab->c_flags[0] != '-')
		print_sign(tab, tab->padding, ' ');
	print_zero(tab, tab->specifier, nbr);
	print_sign(tab, m_z, '0');
	if (tab->specifier == 'X')
		ft_s_toupper(tmp);
	else
		ft_putstr(tmp);
	if (tab->c_flags[0] == '-')
		print_sign(tab, tab->padding, ' ');
	return (0);
}

static int		get_mz(t_tab *tab, uintmax_t nbr, int s_len, int mod)
{
	int			m_z;
	int			prec;

	prec = tab->prec;
	if (tab->c_flags[4] == '0' && prec == -1 && !nbr)
		m_z = tab->width - s_len;
	else if (!nbr && (prec == 0 || prec == -1))
		m_z = 1;
	else if (tab->c_flags[4] == '0' && prec == -1)
		m_z = tab->width - s_len - mod;
	else if (tab->c_flags[4] == '0' && tab->c_flags[3] == '#' && prec != -1)
		m_z = prec - s_len;
	else if (tab->c_flags[4] != '0' && prec && prec > s_len)
		m_z = prec - s_len;
	else if (tab->c_flags[4] != '0' && prec == -1 && nbr)
		m_z = 0;
	else
		m_z = prec - s_len - mod;
	if (tab->c_flags[4] == '0' && tab->c_flags[0] == '-' && tab->prec == -1)
		m_z = 0;
	return (m_z = m_z < 0 ? 0 : m_z);
}

t_tab			*print_x(t_tab *tab)
{
	char		*tmp;
	uintmax_t	nbr;
	int			m_z;
	int			mod;

	m_z = 0;
	nbr = get_oux_nbr(tab);
	if (nbr == 0 && tab->prec == 0)
	{
		print_sign(tab, tab->width, ' ');
		return (tab);
	}
	tmp = ft_itoa_base(nbr, 16);
	mod = (tab->c_flags[3] == '#' && nbr) ? 2 : 0;
	tab->s_len = ft_strlen(tmp);
	m_z = get_mz(tab, nbr, tab->s_len, mod);
	add_z(tab, m_z, mod, nbr);
	do_x(tab, nbr, m_z, tmp);
	tab->len += tab->s_len;
	free(tmp);
	return (tab);
}
