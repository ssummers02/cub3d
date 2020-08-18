/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:59:50 by ssummers          #+#    #+#             */
/*   Updated: 2020/05/28 23:41:43 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

t_tab	*print_c(t_tab *tab)
{
	if (tab->c_flags[0] == '-' && tab->width > 0 && \
		(tab->c_flags[4] == 0 || tab->c_flags[4] != '\0'))
	{
		ft_putchar(va_arg(tab->args, int));
		tab->len += 1;
		while (tab->width - 1 >= 1)
		{
			print_sign(tab, 1, 32);
			tab->width--;
		}
	}
	else
	{
		while ((tab->width - 1) > 0)
		{
			print_sign(tab, 1, 32);
			tab->width--;
		}
		ft_putchar(va_arg(tab->args, int));
		tab->len += 1;
	}
	return (tab);
}
