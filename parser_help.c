#include "cub.h"

int parser_help_r(char *ln, t_parse *parse)
{

	if (*ln == 'R')
	{
		if (parse->x != -1)
			error();
		ln++;
		while (*ln == ' ')
			ln++;
		parse->x = ft_atoi(ln);
		while (ft_isdigit(*ln))
			ln++;
		while (*ln == ' ')
			ln++;
		parse->y = ft_atoi(ln);
		while (ft_isdigit(*ln))
			ln++;
		while (*ln == ' ')
			ln++;
		if (*ln != '\0')
			error();
	}
	return 0;
}

int parser_help_f(char *ln, t_parse *parse)
{

	if (*ln == 'F')
	{
		if (parse->floor->r != -1)
			error();
		ln++;
		while (*ln == ' ')
			ln++;
		parse->floor->r = ft_atoi(ln);
		while (ft_isdigit(*ln))
			ln++;
		if (*ln != ',') error();

		ln++;
		parse->floor->g = ft_atoi(ln);
		while (ft_isdigit(*ln))
			ln++;
		if (*ln != ',') error();

		ln++;
		parse->floor->b = ft_atoi(ln);
		while (ft_isdigit(*ln))
			ln++;
		while (*ln == ' ')
			ln++;
		if (*ln != '\0')
			error();
	}
	return 0;
}

int parser_help_c(char *ln, t_parse *parse)
{

	if (*ln == 'C')
	{
		if (parse->ceilling->r != -1)
			error();
		ln++;
		while (*ln == ' ')
			ln++;
		parse->ceilling->r = ft_atoi(ln);
		while (ft_isdigit(*ln))
			ln++;
		if (*ln != ',') error();

		ln++;
		parse->ceilling->g = ft_atoi(ln);
		while (ft_isdigit(*ln))
			ln++;
		if (*ln != ',') error();

		ln++;
		parse->ceilling->b = ft_atoi(ln);
		while (ft_isdigit(*ln))
			ln++;
		while (*ln == ' ')
			ln++;
		if (*ln != '\0')
			error();
	}
	return 0;
}

int parser_help_no(char *ln, t_parse *parse)
{
	char *temp;

	if (ft_strncmp("NO", ln, 2) == 0)
	{
		if (ft_strlen(parse->NO) != 0)
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
		parse->NO = malloc(sizeof(char) * parse->temp);
		parse->NO = ft_strcpy(parse->NO, temp);
		while (*ln == '.' || *ln == '/' || ft_isalpha(*ln) == 1 || *ln == ' ')
			ln++;
		if (*ln != '\0')
			error();
	}
	return 0;
}

int parser_help_so(char *ln, t_parse *parse)
{
	char *temp;

	if (ft_strncmp("SO", ln, 2) == 0)
	{
		if (ft_strlen(parse->SO) != 0)
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
		parse->SO = malloc(sizeof(char) * parse->temp);
		parse->SO = ft_strcpy(parse->SO, temp);
		while (*ln == '.' || *ln == '/' || ft_isalpha(*ln) == 1 || *ln == ' ')
			ln++;
		if (*ln != '\0')
			error();
	}
	return 0;
}