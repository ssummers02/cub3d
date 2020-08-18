#include <stdio.h>
#include "mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libftprint.h>
#include "get_next_line.h"
#include "libft.h"

typedef struct s_parse {
	int x;
	int y;
	char *NO;
	int temp;

} t_parse;

t_parse *init_parse(t_parse *parse) {
	parse->x = 0;
	parse->y = 0;
	parse->NO = "\0";
	return (parse);
}

int parser(t_parse *parse, char **argv) {
	int gnl;
	int fd;
	char *ln;
	int i;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((gnl = get_next_line(fd, &ln)) > 0) {
		while (*ln == ' ')
			ln++;
		if (*ln == 'R') {
			ln++;
			parse->x = ft_atoi(ln);
			ln++;
			while (ft_isdigit(*ln++))
				parse->y = ft_atoi(ln);
			while (ft_isdigit(*ln))
				ln++;
			while (*ln == ' ')
				ln++;
			if (*ln != '\0') {
				free(ln);
				return (-1);
			}
		}
		if (ft_strncmp("NO", ln, 2) == 0) {
			*ln+=4;
			printf("%c", *ln);
			parse->temp = 1;
			while (*ln != ' ' || *ln != '\n' || *ln != '\0') {
				parse->temp++;
				ln++;
			}
			parse->NO = malloc(sizeof(char) * (int) parse->temp);
			parse->NO = ft_strcpy(parse->NO, ln);
			while (*ln == '.' || *ln == '/' || ft_isalpha(*ln) == 1)
				ln++;
		}
	}
	free(ln);
	close(fd);
	printf("%d %d %s ", parse->x, parse->y, parse->NO);
	return 1; // fix
}

int main(int argc, char **argv) // 3 аргумента
{
	t_parse *parse;

	if (!(parse = (t_parse *) malloc(sizeof(t_parse))))
		return (-1);
	parse = init_parse(parse);
	if (argc > 3) {
		ft_putstr_fd("Error\n", 1);
		return 0;
	}
	if (parser(parse, argv) == -1) {
		ft_putstr_fd("Error\n", 1);
		return 0;
	}
	else {

	}

	return 0;
}
