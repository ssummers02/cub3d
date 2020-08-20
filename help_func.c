#include "cub.h"

void error(char *c)
{
	ft_putstr_fd(c, 1);
	ft_putstr_fd("\n", 1);
	exit(-1);
}

void verification_arg(t_parse *parse)
{
	if (parse->floor->r < 0 || parse->floor->r > 255 ||
		parse->floor->g < 0 || parse->floor->g > 255 ||
		parse->floor->b < 0 || parse->floor->b > 255 ||
		parse->ceilling->r < 0 || parse->ceilling->r > 255 ||
		parse->ceilling->g < 0 || parse->ceilling->g > 255 ||
		parse->ceilling->b < 0 || parse->ceilling->b > 255)
		error("Incorrect color");

	if (parse->x <= 0 || parse->y <= 0 ||
		parse->map->x == 0 || parse->map->y == 0)
		error("Incorrect value maps or resolution");
	/*if (open(parse->NO, O_RDONLY) == -1 || open(parse->WE, O_RDONLY) == -1 ||
		open(parse->SO, O_RDONLY) == -1 || open(parse->EA, O_RDONLY) == -1 ||
		open(parse->S, O_RDONLY) == -1)
			error("Error open map");*/
	verification_map(parse);

}

int validpos(t_parse *parse, int i, int j)
{
	if (parse->maps[i][j] == 'W' || parse->maps[i][j] == 'S' ||
		parse->maps[i][j] == 'E' || parse->maps[i][j] == 'N' ||
		parse->maps[i][j] == '1' || parse->maps[i][j] == '2' ||
		parse->maps[i][j] == '0')
		return 1;
	return 0;
}

void ver(t_parse *parse, int i, int j)
{
	if (validpos(parse, i + 1, j) == 0 || validpos(parse, i, j + 1) == 0 ||
		validpos(parse, i - 1, j) == 0 || validpos(parse, i, j - 1) == 0)
		error("Error maps");
}

void verification_map(t_parse *parse)
{
	int i;
	int j;

	i = 0;
	while (parse->maps[i])
	{
		j = 0;
		while (parse->maps[i][j])
		{
			if (i == 0 || j == 0)
			{
				if (parse->maps[i][j] == '1' || parse->maps[i][j] == ' ')
				{
					j++;
				} else
				{
					error("Error maps");
					j++;
				}


			} else
			{
				ver(parse, i, j);
				j++;

			}

		}
		i++;
	}


}

void inverse(char *string)
{
	int lenght = ft_strlen(string);
	char *p = string;
	char *q = string + lenght - 1;

	while (p > q)
	{
		char tmp = *p;
		*p = *q;
		*q = tmp;

		p++;
		q--;
	}
}