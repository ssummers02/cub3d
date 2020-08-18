/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 22:33:10 by ssummers          #+#    #+#             */
/*   Updated: 2020/05/28 23:40:04 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

t_tab		*check_all_flag(t_tab *tab)
{
	tab->i++;
	if (tab->search_fmt[tab->i] != '\0')
		check_conv_flags(tab);
	if (tab->search_fmt[tab->i] != '\0')
		check_width(tab);
	if (tab->search_fmt[tab->i] != '\0')
		check_precision(tab);
	if (tab->search_fmt[tab->i] != '\0')
		check_arg_flags(tab);
	if (tab->search_fmt[tab->i] != '\0')
		check_specifier(tab);
	if (tab->search_fmt[tab->i] != '\0')
		print_check(tab);
	return (tab);
}
