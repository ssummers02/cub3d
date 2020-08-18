/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 22:33:10 by ssummers          #+#    #+#             */
/*   Updated: 2020/05/28 23:41:43 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

t_tab	*print_check(t_tab *tab)
{
	char	*spec;

	spec = &tab->specifier;
	if (ft_strchr("cspxXdDioufF%", (int)tab->search_fmt[tab->i]))
	{
		if (*spec == 'c')
			print_c(tab);
		else if (*spec == 's')
			print_s(tab);
		else if (*spec == 'p')
			print_p(tab);
		else if (*spec == 'x' || *spec == 'X')
			print_x(tab);
		else if (*spec == 'o')
			print_o(tab);
		else if (*spec == 'u')
			print_u(tab);
		else if (*spec == 'd' || *spec == 'i' || *spec == 'D')
			print_d(tab);
		else if (*spec == 'f' || *spec == 'F')
			print_f(tab);
		else
			print_other(tab);
	}
	return (tab);
}
