/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr(t_stack *a, t_stack *b, int ab)
{
	int pr;

	pr = real_mode(-1);
	real_mode(0);
	rx(a, ab);
	rx(b, !ab);
	if (pr == 1)
		ft_printf("rr\n");
	real_mode(pr);
	return (1);
}

int	ss(t_stack *a, t_stack *b, int ab)
{
	int pr;

	pr = real_mode(-1);
	real_mode(0);
	sx(a, ab);
	sx(b, !ab);
	if (pr == 1)
		ft_printf("ss\n");
	real_mode(pr);
	return (1);
}

int	rrr(t_stack *a, t_stack *b, int ab)
{
	int pr;

	pr = real_mode(-1);
	real_mode(0);
	rrx(a, ab);
	rrx(b, !ab);
	if (pr == 1)
		ft_printf("rrr\n");
	real_mode(pr);
	return (1);
}

int	px(t_stack *a, t_stack *b, int ab)
{
	if (b->first)
	{
		push(a, b->first->n);
		pop(b);
	}
	if (real_mode(-1))
		ft_printf("p%c\n", ab ? 'b' : 'a');
	return (1);
}
