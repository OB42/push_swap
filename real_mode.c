/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/06 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		real_mode(int x)
{
	static int print = 0;

	if (x == 1)
		print = 1;
	else if (!x)
		print = 0;
	return (print);
}
