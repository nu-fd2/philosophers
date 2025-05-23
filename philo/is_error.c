/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd2 <fd2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:51:43 by fd2               #+#    #+#             */
/*   Updated: 2025/04/20 00:51:47 by fd2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_error(char *str, void *p1, void *p2)
{
	if (str)
		printf("\e[1;31m%s\e[0m\n", str);
	if (p1)
		free(p1);
	if (p2)
		free(p2);
	write(2, "\e[1;31mError\e[0m\n", 17);
	exit(1);
}
