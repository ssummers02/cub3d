#include "cub.h"

int parser_help_we(char *ln, t_parse *parse)
{
	char *temp;

	if (ft_strncmp("WE", ln, 2) == 0)
	{
		if (ft_strlen(parse->WE) != 0)
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
		parse->WE = malloc(sizeof(char) * parse->temp);
		parse->WE = ft_strcpy(parse->WE, temp);
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
		if (ft_strlen(parse->EA) != 0)
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
		parse->EA = malloc(sizeof(char) * parse->temp);
		parse->EA = ft_strcpy(parse->EA, temp);
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
			if (ft_strlen(parse->S) != 0)
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
			parse->S = malloc(sizeof(char) * parse->temp);
			parse->S = ft_strcpy(parse->S, temp);
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

void checkmap(char *ln, t_parse *parse)
{
	if (ft_strlen(ln) == 0 && parse->map->y != 0 && parse->map->x != 0)
		error("Not found maps");
	if (ft_strlen(ln) != 0)
		parse->map->y++;
	if (ft_strlen(ln) > parse->map->x)
		parse->map->x = ft_strlen(ln);
}

char *ft_strcpy_space(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i != len)
		while (i < len)
		{
			dst[i] = ' ';
			i++;
		}
	dst[i] = '\0';
	return (dst);
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
	if (!(parse->maps = (char **) malloc(sizeof(char) * parse->map->y)))
		exit(-1);
	check -= parse->map->y;
	i = 0;
	while ((get_next_line(fd, &ln)) > 0)
	{
		if (check > 0)
		{
			check--;
		} else
		{
			if (!(parse->maps[i] = (char *) malloc(
					parse->map->x * sizeof(char))))
				exit(-1);
			ft_strcpy_space(parse->maps[i], ln, parse->map->x);
			i++;
		}

	}
	free(ln);
	close(fd);
	verification_arg(parse);
	printf("%d\t%d\t%d", parse->map->x, parse->map->y, check);

	return 0;
}