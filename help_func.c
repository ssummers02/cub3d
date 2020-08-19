#include "cub.h"

void error()
{
	ft_putstr_fd("Error\n", 1);
	exit(-1);
}

void verification_arg(t_parse *parse)
{
	if (parse->ceilling->r < 0 || parse->ceilling->r > 255 ||
		parse->ceilling->g < 0 || parse->ceilling->g > 255 ||
		parse->ceilling->b < 0 || parse->ceilling->b > 255 ||
		parse->floor->r < 0 || parse->floor->r > 255 ||
		parse->floor->g < 0 || parse->floor->g > 255 ||
		parse->floor->b < 0 || parse->floor->b > 255 ||
		parse->x <= 0 || parse->y <= 0)
		error();
	/*if (open(parse->NO, O_RDONLY) == -1 || open(parse->WE, O_RDONLY) == -1 ||
		open(parse->SO, O_RDONLY) == -1 || open(parse->EA, O_RDONLY) == -1 ||
		open(parse->S, O_RDONLY) == -1)
		error();*/

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