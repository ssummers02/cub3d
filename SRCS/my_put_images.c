#include "../INCLUDES/cub.h"

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

void mlx_create_maps(t_data img, t_parse *parse)
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

void mlx_create_sky_land(t_data img, t_parse *parse)
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


void mlx_create_wall(t_data img, t_parse *parse)
{
	int i;
	i = 0;
	float dis;
	while (i < parse->x)
	{
		dis = 0;
		float angle = parse->player_a - FOV / 2 + FOV * i / (float) parse->x;
		if (angle > 2 * M_PI)
			angle -= 2 * M_PI;
		while (dis < 20)
		{
			double x = parse->player->x + dis * cosf(angle);
			double y = parse->player->y + dis * sinf(angle);
			if (parse->maps[(int) y][(int) x] == '1') break;
			dis += 0.01;
		}
		dis *= cos(angle - parse->player_a);

		int nCeiling = (float) (parse->y / 2.0) - parse->y / ((float) dis);
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

/*
void mlx_create_wall(t_data img, t_parse *parse)
{
	int x;
	x = 0;
	while (x < parse->x)
	{
		float dis = 0.0f;
		float angle = (parse->player_a - FOV / 2.0f) + ((float) x / (float) parse->y) * FOV; // Направление луча
		float fEyeX = sinf(angle); // Координаты единичного вектора angle
		float fEyeY = cosf(angle);
		while (dis < 20)
		{
			dis += 0.1f;
			int nTestX = (int)(parse->x + fEyeX*dis); // Точка на игровом поле
			int nTestY = (int)(parse->y + fEyeY*dis);
			if (nTestX < 0 || nTestX >= parse->x || nTestY < 0 ||
				nTestY >= parse->y)
			{
				dis = 10;
				break;
			}
			else if (parse->maps[nTestY][nTestX] == '1')
				break;
		}
		int nCeiling = (float) (parse->y / 2.0) - parse->y / ((float) dis);
		int nFloor = parse->y - nCeiling;
		while (nCeiling < nFloor)
		{
			my_mlx_pixel_put(&img, x, nCeiling, 0x00FF00);
			nCeiling++;
		}
		x++;

	}
}
*/

