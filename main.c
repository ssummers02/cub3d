#include "cub.h"

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
//	if (ft_strncmp(inverse(argv[1]), "buc.", 3))
	if (argc > 3)
		error("Error count argv");
	if (parser(parse, argv) == -1)
		error("Error");




/*	int fd;
	char *ln;
	int ch;

	int check = 0;
	ch = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((get_next_line(fd, &ln)) > 0)
	{
		check++;
		printf("%s\n", ln);

	}
	printf("%d", check);

	exit(0);*/
}
