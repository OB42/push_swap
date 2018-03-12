/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/06 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_arr(t_intl *t, t_array *arr)
{
	int		x;

	x = 0;
	arr->data = pr_malloc(sizeof(int) * arr->len);
	while (t)
	{
		arr->data[x++] = t->n;
		t = t->next;
	}
}

int		main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_array	arr;

	a.first = 0;
	b.first = 0;
	arr = (t_array){fill_stack(argc, argv, &a, 0), 0};
	if (arr.len < SMALL_STACK_LEN && !empty_stacks(&a, &b))
		arr = (t_array){fill_stack(argc, argv, &a, 1), 0};
	fill_arr(a.first, &arr);
	arr_sort(arr.data, arr.len);
	if (arr.len >= SMALL_STACK_LEN)
		return (is_sorted(&a, 1) ? 0 :
		sort_large_stack((t_stack *[]){&a, &b}, arr, argc, argv));
	else
		sort_small_stack(&a, &b);
	free(arr.data);
	return (empty_stacks(&a, &b));
}
