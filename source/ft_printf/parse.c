/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:56:05 by ssummers          #+#    #+#             */
/*   Updated: 2020/05/28 23:41:43 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

static int	test_validity(t_tab *tab)
{
	int i;

	i = tab->i + 1;
	while (!ft_strchr("cspdDiouxXfF%", (int)tab->c_fmt[i]))
		i++;
	if (tab->c_fmt[i] != '\0')
		return (1);
	return (0);
}

int			parse(t_tab *tab)
{
	int valid;

	valid = 0;
	if (ft_strcmp(tab->c_fmt, "%") == 0)
		return (0);
	while (tab->c_fmt[tab->i] != '\0')
	{
		if (tab->c_fmt[tab->i] == '%')
		{
			valid = test_validity(tab);
			if (valid == 0)
				return (0);
			re_init(tab);
			check_all_flag(tab);
		}
		else
		{
			write(1, &tab->c_fmt[tab->i], 1);
			tab->len++;
		}
		tab->i++;
	}
	return (tab->len);
}
