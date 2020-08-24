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
			else if(parse->maps[i][j] == '0')
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
	mlx_put_sky_land(img, parse);

	mlx_put_maps(img, parse);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

	/*float player_x = parse->player->x; // player x position
	float player_y = parse->player->y;// player y position
	float player_a = 1.523; // player view direction
	const double fov = M_PI / 3.; // field of view
	const size_t win_w = (const size_t) parse->x;
	const size_t win_h = (const size_t) parse->y;
	const size_t map_w = parse->map->x; // map width
	const size_t map_h = parse->map->y;; // map height
	const size_t rect_w = win_w/map_w;
	const size_t rect_h = win_h/map_h;
	for (float t = 0; t < 20; t += .05)
	{
		float cx = player_x + t * cos(player_a);
		float cy = player_y + t * sin(player_a);
		if (parse->maps[(int) (cx)] [(int) (cy) * map_w] != ' ')
			break;
		for (size_t i = 0; i < win_w; i++)
		{ // draw the visibility cone
			float angle = player_a - fov / 2 + fov * i /(win_w);

			size_t pix_x = cx * rect_w;
			size_t pix_y = cy * rect_h;
			ml[pix_x + pix_y * win_w] = pack_color(255, 255, 255);
			for (float t = 0; t < 20; t += .05)
			{
				float cx = player_x + t * cos(angle);
				float cy = player_y + t * sin(angle);
				if (map[int(cx)
				+
				int(cy)
				*map_w]!=' ') break;

				size_t pix_x = cx * rect_w;
				size_t pix_y = cy * rect_h;
				framebuffer[pix_x + pix_y * win_w] = pack_color(255, 255, 255);
			}
		}

*/
	return 1;
}
