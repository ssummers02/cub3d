/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:59:50 by ssummers          #+#    #+#             */
/*   Updated: 2020/07/01 22:45:24 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

static void	help_print(t_tab *tab, char *tmp, int s_len)
{
	if (tab->c_flags[0] != '-' && tab->c_flags[4] == '0')
		print_sign(tab, tab->width - s_len, '0');
	else if (tab->c_flags[0] != '-')
		print_sign(tab, tab->width - s_len, ' ');
	ft_putstr(tmp);
	if (tab->c_flags[0] == '-')
		print_sign(tab, tab->width - s_len, ' ');
	if (tab->width < 0 && ft_strlen(tmp) < (size_t)tab->width * -1)
		print_sign(tab, tab->width * -1 - s_len, ' ');
	tab->len += ft_strlen(tmp);
}

t_tab		*print_s(t_tab *tab)
{
	char	*tmp;
	int		s_len;

	tmp = va_arg(tab->args, char *);
	if (tab->prec == -1 && tmp)
		tmp = ft_strdup(tmp);
	else if (tab->prec == -1 && !tmp)
		tmp = ft_strdup("(null)");
	else if (tab->prec > -1 && tmp)
		tmp = ft_strndup(tmp, tab->prec);
	else if (tab->prec > -1 && !tmp)
		tmp = ft_strndup("(null)", tab->prec);
	else if (tab->prec < 0 && tmp == NULL)
		tmp = ft_strdup("(null)");
	s_len = ft_strlen(tmp);
	help_print(tab, tmp, s_len);
	if ((tab->prec > 0 && s_len > 0) || ft_strcmp(tmp, "(null)") == 0)
		free(tmp);
	return (tab);
}
