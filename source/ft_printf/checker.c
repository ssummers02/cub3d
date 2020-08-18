/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 22:33:10 by ssummers          #+#    #+#             */
/*   Updated: 2020/07/01 22:46:05 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

t_tab		*check_conv_flags(t_tab *tab)
{
	size_t	i;

	i = 0;
	while (tab->format_flags[i] != '\0')
	{
		while (tab->format_flags[i] == tab->search_fmt[tab->i])
		{
			if (tab->search_fmt[tab->i] == '-')
				tab->c_flags[0] = '-';
			else if (tab->search_fmt[tab->i] == '+')
				tab->c_flags[1] = '+';
			else if (tab->search_fmt[tab->i] == ' ')
				tab->c_flags[2] = ' ';
			else if (tab->search_fmt[tab->i] == '#')
				tab->c_flags[3] = '#';
			else if (tab->search_fmt[tab->i] == '0')
				tab->c_flags[4] = '0';
			i = 0;
			tab->i++;
		}
		i++;
	}
	return (tab);
}

t_tab		*check_width(t_tab *tab)
{
	if (tab->fmt[tab->i] == '*')
	{
		tab->width = va_arg(tab->args, int);
		tab->i++;
		return (tab);
	}
	while (ft_isdigit(tab->search_fmt[tab->i]))
	{
		tab->width *= 10;
		tab->width += (tab->search_fmt[tab->i] - 48);
		tab->i++;
	}
	return (tab);
}

t_tab		*check_precision(t_tab *tab)
{
	if (tab->search_fmt[tab->i] == '.')
	{
		tab->prec = 0;
		tab->i++;
	}
	if (tab->fmt[tab->i] == '*')
	{
		tab->prec = va_arg(tab->args, int);
		tab->i++;
		return (tab);
	}
	while (ft_isdigit(tab->search_fmt[tab->i]))
	{
		tab->prec *= 10;
		tab->prec += (tab->search_fmt[tab->i] - 48);
		tab->i++;
	}
	return (tab);
}

t_tab		*check_arg_flags(t_tab *tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (tab->a_flags[i] != '\0')
	{
		while (tab->a_flags[i] == tab->search_fmt[tab->i])
		{
			tab->len_flags[j] = tab->search_fmt[tab->i];
			tab->len_flags[j + 1] = '\0';
			j++;
			tab->i++;
		}
		i++;
	}
	return (tab);
}

t_tab		*check_specifier(t_tab *tab)
{
	int		i;

	i = 0;
	while (tab->spec_flags[i] != '\0')
	{
		if (tab->search_fmt[tab->i] == tab->spec_flags[i])
			tab->specifier = tab->search_fmt[tab->i];
		i++;
	}
	return (tab);
}
