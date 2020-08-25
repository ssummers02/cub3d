#include "../INCLUDES/cub.h"

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void mlx_put_maps_pixel(t_data *data, int x, int y, int color, t_parse *parse)
{
	int j;
	int i;
	int r = 15;
	i = x * r;

	while (i < x * r + r)
	{
		j = y * r;
		while (j < y * r + r)
		{
			my_mlx_pixel_put(data, i, j, color);
			j++;
		}
		i++;
	}
}

void mlx_put_maps(t_data img, t_parse *parse)
{
	int i;
	int j;

	i = 0;
	while (i < parse->maps_y)
	{
		j = 0;
		while (j < parse->maps_x)
		{
			if (parse->maps[i][j] == ' ')
				mlx_put_maps_pixel(&img, j, i, 0xFFFF00, parse);
			else if (parse->maps[i][j] == '2')
				mlx_put_maps_pixel(&img, j, i, 0xFF4500, parse);
			else if (parse->maps[i][j] == '1')
				mlx_put_maps_pixel(&img, j, i, 0x8A2BE2, parse);
			else if (parse->maps[i][j] == '0')
				mlx_put_maps_pixel(&img, j, i, 0x8A8A8A, parse);
			else
				mlx_put_maps_pixel(&img, j, i, 0xFFFFFF, parse);
			j++;
		}

		i++;
	}
}

void mlx_put_sky_land(t_data img, t_parse *parse)
{
	int i;
	int j;

	i = 0;
	int c = create_trgb(0, parse->ceilling->r,
						parse->ceilling->g,
						parse->ceilling->b);
	int f = create_trgb(0, parse->floor->r,
						parse->floor->g,
						parse->floor->b);
	free(parse->floor);
	free(parse->ceilling);
	while (i < parse->y)
	{
		j = 0;
		if (i < parse->y / 2)
			while (j < parse->x)
			{
				my_mlx_pixel_put(&img, j, i, c);
				j++;
			}
		else
			while (j < parse->x)
			{
				my_mlx_pixel_put(&img, j, i, f);
				j++;
			}
		i++;
	}
}

void mlx_put_wall(t_data img, t_parse *parse)
{
	int i;
	double player_a = 1.23;// направление
	i = 0;
	float dis = 0;
	printf("%d\t%d", parse->x, parse->y);
	while (i < parse->x)
	{
		float angle = player_a - FOV / 2 + FOV * i / (float) parse->x;
		while (dis < 20)
		{
			float x = parse->player->x + dis * cosf(angle);
			float y = parse->player->y + dis * sinf(angle);
			if (parse->maps[(int) y][(int) x] == '1') break;
			dis += 0.01;
		}
		dis *= cos(angle - player_a);
		int nCeiling = (float) ((parse->y / 2.0) - parse->y / (float) dis);
		if (nCeiling > parse->y || nCeiling < 0)
			nCeiling = 0;
		int nFloor = parse->y - nCeiling;

		while (nCeiling < nFloor)
		{
			my_mlx_pixel_put(&img, i, nCeiling, 0x00FF00);
			nCeiling++;
		}
		i++;
	}
}

void mlx_put_image(t_data img, t_parse *parse, void *mlx, void *mlx_win)
{
	mlx_put_sky_land(img, parse);
	mlx_put_wall(img, parse);
	mlx_put_maps(img, parse);
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
mlx_put_image(img,parse,mlx,mlx_win);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

	return 1;
}
