#include "philo.h"

int	ft_atoi(const char *str)
{
	int (i), (n);
	i = 0;
	n = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		is_error("arg is empty");
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_error("arg is negative");
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i++] - '0');
		if (n < 0)
			is_error("arg is too big");
	}
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] != '\0')
		is_error("arg is not a number");
	return (n);
}
