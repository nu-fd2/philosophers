#include "philo.h"

void is_error()
{
    write(2, "Error\n", 5);
    exit(1);
}
