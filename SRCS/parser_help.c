#include "../INCLUDES/cub.h"

int parser_help_r(char *ln, t_parse *parse)
{
	if (*ln == 'R')
	{
		if (parse->x != -1)
			error("Incorrect value resolution");
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
			error("Error");
	}
	return 0;
}

int parser_help_f(char *ln, t_parse *parse)
{

	if (*ln == 'F')
	{
		if (parse->floor->r != -1)
			error("Incorrect Floor color");
		ln++;
		while (*ln == ' ')
			ln++;
		parse->floor->r = ft_atoi(ln);
		while (ft_isdigit(*ln))
			ln++;
		if (*ln != ',') error("Error");


		ln++;
		parse->floor->g = ft_atoi(ln);
		while (ft_isdigit(*ln))
			ln++;
		if (*ln != ',') error("Error");


		ln++;
		parse->floor->b = ft_atoi(ln);
		while (ft_isdigit(*ln))
			ln++;
		while (*ln == ' ')
			ln++;
		if (*ln != '\0')
			error("Error");
	}
	return 0;
}

int parser_help_c(char *ln, t_parse *parse)
{

	if (*ln == 'C')
	{
		if (parse->ceilling->r != -1)
			error("Incorrect Ceilling color");
		ln++;
		while (*ln == ' ')
			ln++;
		parse->ceilling->r = ft_atoi(ln);
		while (ft_isdigit(*ln))
			ln++;
		if (*ln != ',')error("Error");

		ln++;
		parse->ceilling->g = ft_atoi(ln);
		while (ft_isdigit(*ln))
			ln++;
		if (*ln != ',') error("Error");

		ln++;
		parse->ceilling->b = ft_atoi(ln);
		while (ft_isdigit(*ln))
			ln++;
		while (*ln == ' ')
			ln++;
		if (*ln != '\0')
			error("Error");
	}
	return 0;
}

int parser_help_no(char *ln, t_parse *parse)
{
	char *temp;

	if (ft_strncmp("NO", ln, 2) == 0)
	{
		if (ft_strlen(parse->no) != 0)
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
		if (!(parse->no = malloc(sizeof(char) * parse->temp)))
			error("Cannot allocate memory");
		parse->no = ft_strcpy(parse->no, temp);
		while (*ln == '.' || *ln == '/' || ft_isalpha(*ln) == 1 || *ln == ' ')
			ln++;
		if (*ln != '\0')
			error("Error");
	}
	return 0;
}

int parser_help_so(char *ln, t_parse *parse)
{
	char *temp;

	if (ft_strncmp("SO", ln, 2) == 0)
	{
		if (ft_strlen(parse->so) != 0)
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
		if (!(parse->so = malloc(sizeof(char) * parse->temp)))
			error("Cannot allocate memory");
		parse->so = ft_strcpy(parse->so, temp);
		while (*ln == '.' || *ln == '/' || ft_isalpha(*ln) == 1 || *ln == ' ')
			ln++;
		if (*ln != '\0')
			error("Error");
	}
	return 0;
}