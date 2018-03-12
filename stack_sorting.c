/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/06 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pa_in_order(t_stack **s, int *op, int y)
{
	t_intl		*t;
	int			i;

	while (s[1]->first)
	{
		rotate_n(s[1], id_minstack(s[1]), op, 1);
		*op += px(s[0], s[1], 0);
	}
	t = s[0]->first;
	i = 0;
	while (t->n <= y && y != maxstack(s[0]))
	{
		i++;
		t = t->next;
	}
	return (i);
}

int		sort_small_stack(t_stack *a, t_stack *b)
{
	int	op;

	real_mode(1);
	if (is_sorted(a, 0) && stlen(a->first) == 3)
		return (sx(a, 0) + rrx(a, 0));
	op = 0;
	while (!is_sorted(a, 1))
	{
		if (stlen(a->first) > 3 && (a->first->n > a->first->next->n)
		&& (a->first->n < a->first->next->next->n))
			op += sx(a, 0);
		if (is_sorted(a, 1))
			break ;
		rotate_n(a, id_minstack(a), &op, 0);
		if (is_sorted(a, 1))
			break ;
		op += px(b, a, 1);
	}
	while (b->first)
		op += px(a, b, 0);
	while (a->first)
		pop(a);
	return (op);
}

int		try_to_sort(t_stack **s, t_array arr, int n, int spl)
{
	static int	op;
	int			w;
	int			x;
	int			y;

	op = n ? op : 0;
	w = 0;
	x = arr.data[arr.len / spl * n];
	y = arr.data[(arr.len / spl * (n + 1) >= arr.len) ?
	arr.len - 1 : (arr.len / spl * (n + 1))];
	while (still(s[0]->first, x, y))
	{
		op += ((s[0]->first->n >= x && s[0]->first->n <= y) ?
		(px(s[1], s[0], 1)) : (rx(s[0], 0)));
	}
	w = pa_in_order(s, &op, y);
	if (n < spl && ((arr.len / spl * (n + 1) >= arr.len) ?
	(arr.len - 1) : (arr.len / spl * (n + 1))) != arr.len - 1)
	{
		rotate_n(s[0], w, &op, 0);
		return (try_to_sort(s, arr, n + 1, spl));
	}
	if (real_mode(-1))
		empty_stacks(s[0], s[1]);
	return (op);
}

int		sort_large_stack(t_stack **s, t_array arr, int argc, char *argv[])
{
	int	div_len;
	int	moves;
	int	min_moves;
	int	best_div_len;

	div_len = arr.len > 3000 ? 10 : 2;
	min_moves = 2147483647;
	best_div_len = div_len;
	while ((div_len < ((arr.len / 2 + 1) > 25 ? 25 : (arr.len / 2 + 1))
	|| min_moves == 2147483647) && !(is_sorted(s[0], 0) && arr.len > 3000))
	{
		reset_stacks(s[0], s[1], argc, argv);
		moves = try_to_sort(s, arr, 0, div_len);
		if (moves < min_moves && is_sorted(s[0], 0) && !s[1]->first)
		{
			min_moves = moves;
			best_div_len = div_len;
		}
		else if (moves > min_moves && (div_len - best_div_len > 5))
			break ;
		div_len++;
	}
	reset_stacks(s[0], s[1], argc, argv);
	real_mode(1);
	return (try_to_sort(s, arr, 0, best_div_len));
}
