/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim <kim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:32:29 by kim               #+#    #+#             */
/*   Updated: 2020/05/03 05:07:03 by kim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cheak(char c, char const *set)
{
	int		j;

	j = 0;
	while (set[j])
	{
		if (set[j] == c)
			return (1);
		j++;
	}
	return (0);
}

static int	ft_trim(const char *c, char const *set)
{
	int		count;
	size_t	i;

	i = 0;
	count = 0;
	while (c[i] && ft_cheak(c[i], set) == 1)
	{
		count++;
		i++;
	}
	i = ft_strlen(c) - 1;
	while (c[i] && ft_cheak(c[i], set) == 1)
	{
		count++;
		i--;
	}
	return (count);
}

static char	*ft_add(char *res, char const *set, char const *s1)
{
	size_t	i;
	int		j;
	size_t	c;

	j = 0;
	i = 0;
	while (s1[i] && ft_cheak(s1[i], set) == 1)
		i++;
	c = ft_strlen(s1) - 1;
	while (ft_cheak(s1[c], set) == 1)
		c--;
	while (s1[i] && i <= c)
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	count;
	char	*result;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	count = ft_trim(s1, set);
	if (count >= ft_strlen(s1))
		return (ft_strdup(""));
	if (!(result = malloc((ft_strlen(s1) - count + 1) * sizeof(char))))
		return (NULL);
	return (ft_add(result, set, s1));
}
