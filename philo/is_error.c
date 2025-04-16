#include "philo.h"

void is_error(char *str)
{
    if (str)
        printf("\e[1;31m%s\e[0m\n", str);
    write(2, "Error\n", 5);
    exit(1);
}
