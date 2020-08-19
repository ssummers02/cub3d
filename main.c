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
	parse = init_parse(parse);
//	if (ft_strncmp(inverse(argv[1]), "buc.", 3))
		if (argc > 3)
			error();
	if (parser(parse, argv) == -1)
		error();


	exit(0);
}
