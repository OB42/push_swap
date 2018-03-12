/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sx(t_stack *s, int ab)
{
	int n;

	if (!s)
		error();
	if (s->first && s->first->next)
	{
		n = s->first->n;
		s->first->n = s->first->next->n;
		s->first->next->n = n;
	}
	if (real_mode(-1))
		ft_printf("s%c\n", ab ? 'b' : 'a');
	return (1);
}

int	rx(t_stack *s, int ab)
{
	int		n;
	t_intl	*t;

	if (!s)
		error();
	if (s->first)
	{
		t = s->first;
		n = pop(s);
		while (t->next)
			t = t->next;
		if (!(t->next = malloc(sizeof(t_intl *))))
			error();
		t->next->n = n;
		t->next->next = 0;
		if (real_mode(-1))
			ft_printf("r%c\n", ab ? 'b' : 'a');
	}
	return (1);
}

int	rrx(t_stack *s, int ab)
{
	t_intl	*t;

	if (!s)
		error();
	if (s->first)
	{
		t = s->first;
		while (t->next && t->next->next)
			t = t->next;
		if (t->next)
		{
			push(s, t->next->n);
			free(t->next);
			t->next = 0;
		}
	}
	if (real_mode(-1))
		ft_printf("rr%c\n", ab ? 'b' : 'a');
	return (1);
}
