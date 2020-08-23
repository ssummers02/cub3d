#include "../INCLUDES/cub.h"

void error(char *c)
{
	ft_putstr_fd(c, 1);
	ft_putstr_fd("\n", 1);
	exit(-1);
}

char *ft_strcpy_space(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i != len)
		while (i < len)
		{
			dst[i] = ' ';
			i++;
		}
	dst[i] = '\0';
	return (dst);
}

void checkmap(char *ln, t_parse *parse)
{
	if (ft_strlen(ln) == 0 && parse->map->y != 0 && parse->map->x != 0)
		error("Not found maps");
	if (ft_strlen(ln) != 0)
		parse->map->y++;
	if (ft_strlen(ln) > parse->map->x)
		parse->map->x = ft_strlen(ln);
}
