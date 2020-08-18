/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim <kim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:19:44 by kim               #+#    #+#             */
/*   Updated: 2020/05/13 17:19:44 by kim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** ft_strjoin_gnl добавляем символы в строку s1 из строки s2
** возвращает NULL при ошибке или результирующую строку после
** склеивания двух строк
*/

char			*ft_strjoin_gnl(char *s1, char *s2)
{
	char		*result;
	size_t		len_s1;
	size_t		len_s2;
	size_t		len;

	len_s1 = 0;
	len_s2 = ft_strlen(s2);
	if (s1 != NULL)
		len_s1 = ft_strlen(s1);
	len = len_s1 + len_s2;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		ft_strlcpy(result, s1, (len_s1 + 1));
		ft_strdel(&s1);
	}
	ft_strlcpy(result + len_s1, s2, (len_s2 + 1));
	return (result);
}

/*
** ft_strdel очищяет память
*/

void			ft_strdel(char **as)
{
	if (as != NULL && *as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

/*
** ft_strchr ищет символ c в строке s и возвращает указатель на первое
** вхождение искомого символа
*/

char			*ft_strchr(const char *s, int c)
{
	char		*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == (char)c)
		return (str);
	return (NULL);
}

/*
** ft_add_line добавляет строку s в line, далее перезаписывает строку s
** начиная со следующего символа после '\n'
** len - длина будущей строки s после копирования
** find - позиция символа '\n'
** end позиция до которой мы копируем s в line
*/

static int		ft_add_line(char **s, char **line)
{
	char		*find;
	size_t		end;
	size_t		len;

	find = NULL;
	if ((find = ft_strchr(*s, '\n')) != NULL)
	{
		end = find - *s;
		len = ft_strlen(find);
		*line = ft_substr(*s, 0, end);
		ft_strlcpy(*s, (find + 1), (len + 1));
		return (1);
	}
	return (0);
}

/*
** get_next_line считывает строку до первого вхождения сивола '\n' или
** окончания файла (EOF)
** возвращаемые значения
** 1: строка была прочитана
** 0: EOF достигнут
** -1: произошла ошибка
*/

int				get_next_line(int fd, char **line)
{
	int			i;
	char		buff[BUFF_SIZE + 1];
	static char	*s;

	if (line == NULL || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (s != NULL && ft_add_line(&s, line) == 1)
		return (1);
	while ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		if ((s = ft_strjoin_gnl(s, buff)) == NULL)
			return (-1);
		if (ft_add_line(&s, line) == 1)
			return (1);
	}
	if (s == NULL)
		*line = ft_strdup("");
	else
		*line = ft_strdup(s);
	ft_strdel(&s);
	return (i);
}
