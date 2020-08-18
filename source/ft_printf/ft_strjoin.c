/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssummers <ssummers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:27:15 by ssummers          #+#    #+#             */
/*   Updated: 2020/05/28 23:41:40 by ssummers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*result;

	i = 0;
	if (!s1 || !s2 ||
		!(result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		result[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	result[ft_strlen(s1) + i] = '\0';
	return (result);
}
