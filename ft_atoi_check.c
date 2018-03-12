/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoi_check(const char *str)
{
	int			i;
	long long	nb;
	int			negative;

	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	negative = *str == '-' ? -1 : 1;
	if (ft_strchr("+-", *str))
		str++;
	nb = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb * negative < -2147483648 || nb * negative > 2147483647)
			error();
		i++;
	}
	if (!i || !(!str[i] || str[i] == ' '))
		error();
	return (nb * negative);
}
