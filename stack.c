/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pop(t_stack *stack)
{
	int		n;
	t_intl	*temp;

	if (!stack)
		error();
	n = 0;
	if (stack->first)
	{
		n = stack->first->n;
		temp = stack->first;
		stack->first = stack->first->next;
		free(temp);
	}
	return (n);
}

void	push(t_stack *stack, int n)
{
	t_intl	*elem;

	if (!stack || !(elem = malloc(sizeof(elem))))
		error();
	else
	{
		elem->n = n;
		elem->next = stack->first;
		stack->first = elem;
	}
}

void	reset_stacks(t_stack *a, t_stack *b, int argc, char *argv[])
{
	int l;

	l = stlen(a->first) + stlen(b->first);
	empty_stacks(a, b);
	fill_stack(argc, argv, a, l < SMALL_STACK_LEN);
}

void	rotate_n(t_stack *s, int n, int *op, int ab)
{
	if (stlen(s->first) - n < n)
	{
		n = stlen(s->first) - n;
		while (n--)
			*op += rrx(s, ab);
	}
	else
	{
		while (n--)
			op += rx(s, ab);
	}
}

int		empty_stacks(t_stack *a, t_stack *b)
{
	while (a->first)
		pop(a);
	while (b->first)
		pop(b);
	return (0);
}
