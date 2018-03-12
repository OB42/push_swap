/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *s)
{
	t_intl *t;

	if (s)
	{
		t = s->first;
		while (t)
		{
			ft_printf("%i ", t->n);
			t = t->next;
		}
	}
	write(1, "\n", 1);
}

void	print_stack_ps(t_stack *s)
{
	t_intl *t;

	if (s)
	{
		t = s->first;
		while (t)
		{
			ft_printf("%i_", t->n > 0 ? (2147483647 - (-2147483648 - t->n))
			: (-2147483648 + (2147483647 - t->n)));
			t = t->next;
		}
	}
	write(1, "\n", 1);
}
