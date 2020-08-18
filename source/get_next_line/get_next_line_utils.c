/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim <kim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:19:35 by kim               #+#    #+#             */
/*   Updated: 2020/05/13 17:19:35 by kim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** ft_strcpy  копирует строку src, включая завершающий нулевой символ в строку
** назначения, на которую ссылается указатель dst.
** возвращает указатель на строку назначения (dst)
*/

char		*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i += 1;
	}
	dst[i] = src[i];
	return (dst);
}

/*
** ft_strlen подсчитывает количесво символов в строке
** возвращает количество символов в строке
*/

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
** ft_substr возвращает подстроку заданной длины
** s — указатель на просматриваемую строку
** start — начальная позиция выделяемой подстроки в s
** length — длина выделяемой подстроки. Если этот параметр отрицателен,
** то указывает смещение относительно конца строки.
*/

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*result;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	if (!(result = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*
** ft_strdup – дублирование строк с выделением памяти под новую строку.
** s1 – указатель на дублируемую строку
** Возвращает NULL – если не удалость выделить память под новую строку или
** скопировать строку на которую указывает аргумент s1
** или Указатель на дублирующую строку
*/

char		*ft_strdup(const char *s1)
{
	char	*dest;

	dest = malloc((ft_strlen(s1) + 1) * sizeof(char));
	return (dest ? ft_strcpy(dest, s1) : dest);
}

/*
** strlcpy копирует из строки src в буфер dst не более чем size - 1 символов и
** гарантированно устанавливает в конец строки нулевой символ.
** возвращает размер строки по адресу src
*/

size_t		ft_strlcpy(char *dst, char const *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
