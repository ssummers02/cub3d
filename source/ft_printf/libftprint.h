/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 22:33:10 by ssummers          #+#    #+#             */
/*   Updated: 2020/05/28 23:41:42 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINT_H
# define LIBFTPRINT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <zconf.h>
# include <stddef.h>
# include <stdarg.h>
# include <ctype.h>

typedef struct	s_tab
{
	const char	*fmt;
	char		*c_fmt;
	char		*search_fmt;
	va_list		args;
	size_t		i;
	int			len;
	int			padding;
	char		specifier;
	long int	width;
	int			s_len;
	long int	prec;
	char		len_flags[3];
	char		c_flags[6];
	char		*hex_chars;
	char		*format_flags;
	char		*a_flags;
	char		*spec_flags;
	char		ch_plus;
}				t_tab;

t_tab			*print_sign(t_tab *tab, int amount, int c);
t_tab			*re_init(t_tab *tab);
t_tab			*check_all_flag(t_tab *tab);
t_tab			*check_width(t_tab *tab);
t_tab			*check_conv_flags(t_tab *tab);
t_tab			*initialize(t_tab *tab);
t_tab			*print_c(t_tab *tab);
t_tab			*print_s(t_tab *tab);
t_tab			*print_p(t_tab *tab);
t_tab			*print_o(t_tab *tab);
t_tab			*print_d(t_tab *tab);
t_tab			*check_precision(t_tab *tab);
t_tab			*check_arg_flags(t_tab *tab);
t_tab			*check_specifier(t_tab *tab);
t_tab			*print_check(t_tab *tab);
t_tab			*print_x(t_tab *tab);
t_tab			*add_z(t_tab *tab, int m_z, int mod, uintmax_t nbr);
t_tab			*print_u(t_tab *tab);
t_tab			*print_f(t_tab *tab);
void			*ft_memset(void *b, int c, size_t len);
int				ft_printf(const char *format, ...);
int				parse(t_tab *tab);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isdigit(int c);
char			*ft_itoa_base(uintmax_t nbr, int base);
void			ft_putstr(char *s);
char			*ft_strdup(const char *s1);
char			*ft_strndup(char *str, int size);
char			*ft_strnew(size_t size);
void			*ft_memalloc(size_t size);
void			ft_bzero(void *s, size_t n);
char			*ft_itoa_uintmax(uintmax_t n);
int				ft_nbr_size_base(uintmax_t nbr, int base);
int				ft_intlen_max(uintmax_t nbr);
char			*ft_ftoa(long double nbr, int prec, char dot);
void			nb_max(t_tab *tab);
void			do_max(void);
int				ft_nbr_size(intmax_t nbr);
void			ft_putnbrmax(intmax_t nbr);
void			print_other(t_tab *tab);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putchar(char c);
void			ft_s_toupper(char *str);
void			help_d(t_tab *tab, int zeroes);
size_t			ft_strlen(const char *s);
intmax_t		get_d_nbr(t_tab *tab);
long double		get_float(t_tab *tab);
uintmax_t		get_oux_nbr(t_tab *tab);
#endif
