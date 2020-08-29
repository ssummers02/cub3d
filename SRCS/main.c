#include "../INCLUDES/cub.h"






void mlx_create_image(t_data img, t_parse *parse, void *mlx, void *mlx_win)
{
	mlx_create_sky_land(img, parse);
	mlx_create_wall(img, parse);
	mlx_create_maps(img, parse);
}

int main(int argc, char **argv)
{
	t_parse *parse;
	void *mlx;
	void *mlx_win;
	t_data img;

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
	parse = init_parse(parse);
	check_name_file(argv[1]);
	if (parser(parse, argv) == -1)
		error("Error");


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, parse->x, parse->y, "cub3D");
	img.img = mlx_new_image(mlx, parse->x, parse->y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	mlx_create_image(img, parse, mlx, mlx_win);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

	return 1;
}
