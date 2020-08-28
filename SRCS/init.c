#include "../INCLUDES/cub.h"

t_parse *init_parse(t_parse *parse)
{
	parse->x = -1;
	parse->y = -1;
	parse->NO = "\0";
	parse->SO = "\0";
	parse->WE = "\0";
	parse->EA = "\0";
	parse->S = "\0";
	parse->floor->r = -1;
	parse->floor->g = -1;
	parse->floor->b = -1;
	parse->ceilling->r = -1;
	parse->ceilling->g = -1;
	parse->ceilling->b = -1;
	parse->maps_x = 0;
	parse->maps_y = 0;
	parse->player->x = 0;
	parse->player->y = 0;

	return (parse);
}

void initplayers(t_parse *parse)
{

	if (parse->maps[parse->player->y][parse->player->x] == 'N')
		parse->player_a = 0;
	if (parse->maps[parse->player->y][parse->player->x] == 'E')
		parse->player_a = 1.5708;
	if (parse->maps[parse->player->y][parse->player->x] == 'S')
		parse->player_a = 3.14159;
	if (parse->maps[parse->player->y][parse->player->x] == 'W')
		parse->player_a = 4.71239;
}