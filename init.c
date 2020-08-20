#include "cub.h"

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
	parse->map->x = 0;
	parse->map->y = 0;
	return (parse);
}