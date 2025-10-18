/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:51:43 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/30 12:22:06 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void prnt_err(char *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	return ;
}

void	is_error(t_data *data, char *err, int ts)
{
	if (err)
		prnt_err(err);
	p_clean(data);
	exit(1);
}
