/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_string_array(char **arr)
{
	int i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	if (arr)
		free(arr);
}

void	check_duplicates(t_stack *s)
{
	t_intl *t;
	t_intl *tt;

	if (!s->first)
		return ;
	t = s->first;
	while (t && t->next)
	{
		tt = t;
		t = t->next;
		while (t)
		{
			if (t->n == tt->n)
				error();
			t = t->next;
		}
		t = tt->next;
	}
}

void	invn(t_stack *s, int n)
{
	t_intl *t;

	if (!(s->first) || !n)
		return ;
	t = s->first;
	while (t)
	{
		t->n = (t->n < 0 ? (2147483647 + (-2147483648 - t->n))
		: (-2147483648 + (2147483647 - t->n)));
		t = t->next;
	}
}

int		chararrlen(char **arr)
{
	int i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

int		fill_stack(int argc, char *argv[], t_stack *stack, int inv)
{
	int		i;
	int		n;
	int		y;
	char	**temp;

	if (argc < 2)
		return (0);
	i = argc - 1;
	while (i > 0)
	{
		temp = ft_split_arg(argv[i--]);
		y = chararrlen(temp) - 1;
		while (y > -1)
		{
			n = ft_atoi_check(temp[y--]);
			push(stack, n);
		}
		free_string_array(temp);
	}
	check_duplicates(stack);
	invn(stack, inv && (stlen(stack->first) >= SMALL_STACK_LEN));
	return (stlen(stack->first));
}
