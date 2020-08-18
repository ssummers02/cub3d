#include <stdio.h>
#include "mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_parse
{
    int x;
    int y;

} t_parse;

t_parse *init_parse(t_parse *parse)
{
    parse->x = 0;
    parse->y = 0;

    return (parse);
}

int parser(t_parse *parse)
{
    int gnl;
    int fd;

    fd = open();
    while ((gnl = get_next_line(fd, &ln)) >= 0)
    {

    }
}

int main(char **argv, int argc) // 3 аргумента
{
    t_parse *parse;

    if (!(parse = (t_parse *) malloc(sizeof(t_parse))))
        return (-1);
    parse = init_parse(parse);
    if (argc < 4)
    {
        ft_put("Error\n");
        return 0;
    }
    parser(parse);

    return 0;
}
