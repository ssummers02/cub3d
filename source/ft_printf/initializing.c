/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 22:33:10 by ssummers          #+#    #+#             */
/*   Updated: 2020/05/28 23:41:41 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

t_tab	*initialize(t_tab *tab)
{
	tab->i = 0;
	tab->len = 0;
	tab->padding = 0;
	tab->s_len = 0;
	tab->format_flags = "#0-+ ";
	tab->a_flags = "lhL";
	tab->spec_flags = "cspdiouxXfF%";
	tab->hex_chars = "0123456789abcdef";
	tab->c_fmt = (char *)tab->fmt;
	tab->search_fmt = (char *)tab->fmt;
	return (tab);
}

t_tab	*re_init(t_tab *tab)
{
	tab->ch_plus = '\0';
	tab->specifier = '\0';
	tab->prec = -1;
	tab->width = 0;
	tab->c_flags[0] = '\0';
	tab->c_flags[1] = '\0';
	tab->c_flags[2] = '\0';
	tab->c_flags[3] = '\0';
	tab->c_flags[4] = '\0';
	tab->c_flags[5] = '\0';
	tab->len_flags[0] = '\0';
	tab->len_flags[1] = '\0';
	tab->len_flags[2] = '\0';
	return (tab);
}
