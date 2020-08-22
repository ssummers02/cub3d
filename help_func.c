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
		parse->maps[i][j] == '2' || parse->maps[i][j] == '1' ||
		parse->maps[i][j] == '0')
		return 1;
	return 0;
}

void ver(t_parse *parse, int i, int j)
{
	if (validpos(parse, i + 1, j) != 1 || validpos(parse, i, j + 1) != 1 ||
		validpos(parse, i - 1, j) != 1 || validpos(parse, i, j - 1) != 1)
		error("Error maps");
}


void verification_map(t_parse *parse)
{
	int i;
	int j;
	int flag;

	i = 0;
	flag = 0;
	while (i < parse->map->y)
	{
		j = 0;
		printf("%s\n", parse->maps[i]);
		while (j < parse->map->x)
		{
			if (parse->maps[i][j] == 'W' || parse->maps[i][j] == 'S' ||
				parse->maps[i][j] == 'E' || parse->maps[i][j] == 'N')
				flag++;
			if (parse->maps[i][j] != '1' && parse->maps[i][j] != ' ')
			{
				if (!(i == 0 || j == 0 || j == parse->map->x - 1 ||
					  i == parse->map->y - 1) && parse->maps[i][j] == '1')
					error("Error maps");
				ver(parse, i, j);
			}
			j++;
		}

		i++;
	}
	if (flag != 1)
		error("Error players");
}

void check_name_file(char *string)
{
	if (string[ft_strlen(string)-1] != 'b' ||
		string[ft_strlen(string) - 2] != 'u' ||
		string[ft_strlen(string) - 3] != 'c' ||
		string[ft_strlen(string) - 4] != '.' )
		error("Invalid .cub");
}