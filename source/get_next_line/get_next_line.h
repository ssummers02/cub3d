/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim <kim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:19:30 by kim               #+#    #+#             */
/*   Updated: 2020/05/13 17:19:30 by kim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEX_LINE_GET_NEXT_LINE_H
# define GET_NEX_LINE_GET_NEXT_LINE_H
# define BUFF_SIZE 16

# include <stdlib.h>
# include <zconf.h>

void	ft_strdel(char **as);
int		get_next_line(int fd, char **line);
size_t	ft_strlcpy(char *dst, char const *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
#endif
