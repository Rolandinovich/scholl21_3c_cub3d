#include "parsing/parsing.h"

int main() {
    char *line;
    int fd;
    int ret;

    fd = open("../input_data", O_RDONLY);
    while ((ret=get_next_line(fd, &line))>=0)
    {
        ft_putstr_fd(line,1);
        ft_putstr_fd("\n",1);
        free(line);
        if (ret == 0)
            break;
    }

    printf("Hello, World!\n");
    return 0;
}
