/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	id_minstack(t_stack *s)
{
	t_intl	*t;
	int		i;
	int		m;
	int		id;

	m = 2147483647;
	i = 0;
	if (!(t = s->first))
		return (-1);
	while (t)
	{
		if (t->n <= m)
		{
			m = t->n;
			id = i;
		}
		t = t->next;
		i++;
	}
	return (id);
}

int	stlen(t_intl *t)
{
	int	i;

	i = 0;
	while (t)
	{
		t = t->next;
		i++;
	}
	return (i);
}

int	maxstack(t_stack *s)
{
	t_intl	*t;
	int		i;
	int		m;

	m = -2147483648;
	i = 0;
	t = s->first;
	while (t)
	{
		if (t->n > m)
			m = t->n;
		t = t->next;
		i++;
	}
	return (m);
}

int	still(t_intl *t, int x, int y)
{
	while (t)
	{
		if (t->n >= x && t->n <= y)
			return (1);
		t = t->next;
	}
	return (0);
}

int	is_sorted(t_stack *s, int order)
{
	t_intl *t;

	if (!s->first)
		return (1);
	t = s->first;
	while (t->next)
	{
		if (order ? (t->n > t->next->n) : (t->n < t->next->n))
			return (0);
		t = t->next;
	}
	return (1);
}
