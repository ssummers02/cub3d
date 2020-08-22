#include "cub.h"
#include "mlx.h"

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_data;
void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int main(int argc, char **argv)
{
	t_parse *parse;

	if (!(parse = (t_parse *) malloc(sizeof(t_parse))))
		return (-1);
	if (!(parse->ceilling = (t_color *) malloc(sizeof(parse->ceilling))))
		return (-1);
	if (!(parse->floor = (t_color *) malloc(sizeof(parse->floor))))
		return (-1);
	if (!(parse->map = (t_map *) malloc(sizeof(parse->map))))
		return (-1);
	parse = init_parse(parse);
	check_name_file(argv[1]);
	if (argc > 3)
		error("Error count argv");
	if (parser(parse, argv) == -1)
		error("Error");


	void    *mlx;
	void    *mlx_win;
	t_data  img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
