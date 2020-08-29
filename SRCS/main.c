#include "../INCLUDES/cub.h"


void mlx_create_image(t_data img, t_parse *parse)
{
	mlx_create_sky_land(img, parse);
	mlx_create_wall(img, parse);
	mlx_create_maps(img, parse);
}

int keys(int keykode, t_parse *parse)
{
	if (keykode == ESC)
	{
		mlx_destroy_window(parse->img->mlx, parse->img->mlx_win);
		exit(1);
	}
	if (keykode == RIGHT)
	{
		/*	if (parse->player_a + 0.1 > 2 * M_PI)
				parse->player_a = parse->player_a + 0.1 - 2 * M_PI;
			else*/
		parse->player_a += 0.05;
		mlx_create_image(*(parse->img), parse);
		mlx_put_image_to_window(parse->img->mlx, parse->img->mlx_win,
								parse->img->img, 0, 0);

	}
	if (keykode == LEFT)
	{
		/*	if (parse->player_a - 0.1 < 0)
				parse->player_a = parse->player_a - 0.1 + 2 * M_PI;
			else*/
		parse->player_a -= 0.05;
		mlx_create_image(*(parse->img), parse);
		mlx_put_image_to_window(parse->img->mlx, parse->img->mlx_win,
								parse->img->img, 0, 0);

	}


	return 0;
}

int main(int argc, char **argv)
{
	t_parse *parse;


	if (argc > 3)
		error("Error count argv");
	if (!(parse = malloc(sizeof(t_parse))))
		error("Cannot allocate memory");
	if (!(parse->floor = malloc(sizeof(t_color *))))
		error("Cannot allocate memory");
	if (!(parse->ceilling = malloc(sizeof(t_color *))))
		error("Cannot allocate memory");
	if (!(parse->player = malloc(sizeof(t_map *))))
		error("Cannot allocate memory");
	if (!(parse->img = malloc(sizeof(t_data *))))
		error("Cannot allocate memory");
	parse = init_parse(parse);
	check_name_file(argv[1]);
	if (parser(parse, argv) == -1)
		error("Error");

	parse->img->mlx = mlx_init();
	parse->img->mlx_win = mlx_new_window(parse->img->mlx, parse->x, parse->y,
										 "cub3D");
	parse->img->img = mlx_new_image(parse->img->mlx, parse->x, parse->y);
	parse->img->addr = mlx_get_data_addr(parse->img->img,
										 &parse->img->bits_per_pixel,
										 &parse->img->line_length,
										 &parse->img->endian);

	mlx_create_image(*(parse->img), parse);
	mlx_put_image_to_window(parse->img->mlx, parse->img->mlx_win,
							parse->img->img, 0, 0);
	mlx_hook(parse->img->mlx_win, 2, 0, keys, parse);
	mlx_loop(parse->img->mlx);

	return 1;
}
