#include "../INCLUDES/cub.h"

int parser_help_we(char *ln, t_parse *parse)
{
	char *temp;

	if (ft_strncmp("WE", ln, 2) == 0)
	{
		if (ft_strlen(parse->we) != 0)
			error("Incorrect texture");
		ln += 2;
		while (*ln == ' ')
			ln++;
		parse->temp = 1;
		temp = ln;
		while ((*ln != ' ' && *ln != '\n') && *ln != '\0')
		{
			parse->temp++;
			ln++;
		}
		if (!(parse->we = malloc(sizeof(char) * parse->temp)))
			error("Cannot allocate memory");
		parse->we = ft_strcpy(parse->we, temp);
		while (*ln == '.' || *ln == '/' || ft_isalpha(*ln) == 1 || *ln == ' ')
			ln++;
		if (*ln != '\0')
			error("Error");
	}
	return 0;
}

int parser_help_ea(char *ln, t_parse *parse)
{
	char *temp;

	if (ft_strncmp("EA", ln, 2) == 0)
	{
		if (ft_strlen(parse->ea) != 0)
			error("Incorrect texture");
		ln += 2;
		while (*ln == ' ')
			ln++;
		parse->temp = 1;
		temp = ln;
		while ((*ln != ' ' && *ln != '\n') && *ln != '\0')
		{
			parse->temp++;
			ln++;
		}
		if (!(parse->ea = malloc(sizeof(char) * parse->temp)))
			error("Cannot allocate memory");
		parse->ea = ft_strcpy(parse->ea, temp);
		while (*ln == '.' || *ln == '/' || ft_isalpha(*ln) == 1 || *ln == ' ')
			ln++;
		if (*ln != '\0')
			error("Error");

	}
	return 0;

}

int parser_help_s(char *ln, t_parse *parse)
{
	char *temp;

	if (ft_strncmp("S", ln, 1) == 0)
	{
		ln += 1;
		if (*ln != 'O')
		{
			if (ft_strlen(parse->s) != 0)
				error("Incorrect texture");
			while (*ln == ' ')
				ln++;
			parse->temp = 1;
			temp = ln;
			while ((*ln != ' ' && *ln != '\n') && *ln != '\0')
			{
				parse->temp++;
				ln++;
			}
			if (!(parse->s = malloc(sizeof(char) * parse->temp)))
				error("Cannot allocate memory");
			parse->s = ft_strcpy(parse->s, temp);
			while (*ln == '.' || *ln == '/' || ft_isalpha(*ln) == 1 ||
				   *ln == ' ')
				ln++;
			if (*ln != '\0')
				error("Error");
		}
	}
	return 0;
}

int parser_help(char *ln, t_parse *parse)
{
	if (ft_strlen(ln) > 0)
	{
		if (ft_strncmp("S", ln, 1) == 0 || ft_strncmp("F", ln, 1) == 0 ||
			ft_strncmp("R", ln, 1) == 0 || ft_strncmp("C", ln, 1) == 0 ||
			ft_strncmp("NO", ln, 2) == 0 || ft_strncmp("SO", ln, 2) == 0 ||
			ft_strncmp("WE", ln, 2) == 0 || ft_strncmp("EA", ln, 2) == 0)
		{
			parser_help_r(ln, parse);
			parser_help_we(ln, parse);
			parser_help_no(ln, parse);
			parser_help_ea(ln, parse);
			parser_help_so(ln, parse);
			parser_help_s(ln, parse);
			parser_help_c(ln, parse);
			parser_help_f(ln, parse);

		} else
			error("Error");
	} else
		return 1;
	return 0;

}


int parser(t_parse *parse, char **argv)
{
	int fd;
	char *ln;
	int i;

	int check = 0;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((get_next_line(fd, &ln)) > 0)
	{
		check++;
		if (i < 8)
		{
			if (parser_help(ln, parse) == 0)
				i++;
		} else
			checkmap(ln, parse);
	}
	free(ln);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (!(parse->maps = (char **) malloc(sizeof(char) * parse->maps_y)))
		exit(-1);
	check -= parse->maps_y;
	i = 0;
	while ((get_next_line(fd, &ln)) > 0)
	{
		if (check > 0)
		{
			check--;
		} else
		{
			if (!(parse->maps[i] = (char *) malloc(parse->maps_x * sizeof(char))))
				exit(-1);
			ft_strcpy_space(parse->maps[i], ln, parse->maps_x);
			i++;
		}

	}
	free(ln);
	close(fd);
	verification_arg(parse);
	initplayers(parse);
	printf("%d\t%d", parse->maps_x, parse->maps_y);
	return 0;
}