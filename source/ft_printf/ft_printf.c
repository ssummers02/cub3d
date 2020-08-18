/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:03:28 by ssummers          #+#    #+#             */
/*   Updated: 2020/05/28 23:41:37 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

int		ft_printf(const char *format, ...)
{
	t_tab	*tab;

	if (!(tab = (t_tab*)malloc(sizeof(t_tab))))
		return (-1);
	tab->fmt = format;
	tab = initialize(tab);
	if (format)
	{
		va_start(tab->args, format);
		tab->len = parse(tab);
		va_end(tab->args);
	}
	free(tab);
	return (tab->len);
}
