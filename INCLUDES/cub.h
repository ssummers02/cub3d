#ifndef CUB3D_CUB_H
#define CUB3D_CUB_H

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>

#define FOV 1.15192
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define W 13
# define A 0
# define S 1
# define D 2
typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;
typedef struct s_color
{
	int r;
	int g;
	int b;
} t_color;
typedef struct s_map
{
	size_t x;
	size_t y;
} t_map;
typedef struct s_parse
{
	int x;
	int y;
	char *no;
	char *so;
	char *we;
	char *ea;
	char *s;
	t_color *floor;
	t_color *ceilling;
	int temp;
	int maps_y;
	int maps_x;
	char **maps;
	t_map *player;
	double player_a;

} t_parse;
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
void mlx_put_maps_pixel(t_data *data, int x, int y, int color, t_parse *parse);
void mlx_create_maps(t_data img, t_parse *parse);
void mlx_create_wall(t_data img, t_parse *parse);
void mlx_create_sky_land(t_data img, t_parse *parse);
int create_trgb(int t, int r, int g, int b)
;
void initplayers(t_parse *parse);

void error(char *c);

void verification_map(t_parse *parse);

int parser_help_r(char *ln, t_parse *parse);

char *ft_strcpy_space(char *dst, const char *src, size_t len);

void checkmap(char *ln, t_parse *parse);

int parser_help_f(char *ln, t_parse *parse);

int parser_help_c(char *ln, t_parse *parse);

int parser_help_no(char *ln, t_parse *parse);

int parser_help_so(char *ln, t_parse *parse);

void verification_arg(t_parse *parse);

t_parse *init_parse(t_parse *parse);

int parser(t_parse *parse, char **argv);

void check_name_file(char *string);

#endif //CUB3D_CUB_H
