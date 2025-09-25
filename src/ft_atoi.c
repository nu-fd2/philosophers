/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd2 <fd2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:51:55 by fd2               #+#    #+#             */
/*   Updated: 2025/04/20 00:53:48 by fd2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int (i), (n);
	i = 0;
	n = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		is_error("arg is empty", NULL, NULL);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_error("arg is negative", NULL, NULL);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i++] - '0');
		if (n < 0)
			is_error("arg is too big", NULL, NULL);
	}
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] != '\0')
		is_error("arg is not a number", NULL, NULL);
	return (n);
}
