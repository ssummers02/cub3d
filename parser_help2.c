#include "cub.h"

int parser_help_we(char *ln, t_parse *parse)
{
	char *temp;

	if (ft_strncmp("WE", ln, 2) == 0)
	{
		if (ft_strlen(parse->WE) != 0)
			error();
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
			error();
	}
	return 0;
}

int parser_help_ea(char *ln, t_parse *parse)
{
	char *temp;

	if (ft_strncmp("EA", ln, 2) == 0)
	{
		if (ft_strlen(parse->EA) != 0)
			error();
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
			error();

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
				error();
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
				error();
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
			error();
	} else
		return 1;
	return 0;

}

int parser(t_parse *parse, char **argv)
{
	int fd;
	char *ln;
	int ch;

	ch = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	while (( get_next_line(fd, &ln)) >= 0)
	{
		if (ch < 8)
		{
			if (parser_help(ln, parse) == 0)
				ch++;
		} else
			printf("%s\n", ln);
		printf("%s\n", ln);

	}
	free(ln);
	close(fd);
	//verification_arg(parse);
	return 0;
}