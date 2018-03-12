/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/06 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		fop(char *s, char *op[], int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (!ft_strcmp(op[i], s))
			return (i);
		i++;
	}
	return (-1);
}

int		exec(t_stack *a, t_stack *b, int (*op_ab[3])(t_stack *, t_stack *,
	int), int (*op_x[3])(t_stack *, int))
{
	int		g;
	char	*temp;

	temp = 0;
	if ((g = get_next_line(0, &temp)) == 1)
	{
		if (!ft_strcmp(temp, "pa") || !ft_strcmp(temp, "pb"))
			px(temp[1] == 'a' ? a : b, temp[1] == 'a' ? b : a, temp[1] == 'b');
		else if (fop(temp, OP, 6) != -1)
			(*op_x[fop(temp, OP, 6) / 2])(ft_strchr(temp, 'a') ? a : b,
			!ft_strchr(temp, 'a'));
		else if (fop(temp, (char *[]){"ss", "rr", "rrr"}, 3) != -1)
			(*op_ab[fop(temp, (char *[]){"ss", "rr", "rrr"}, 3)])(a, b, 0);
		else
			error();
		if (real_mode(-1))
		{
			write(1, temp, ft_strlen(temp));
			write(1, "\n", 1);
		}
	}
	if (temp)
		free(temp);
	return (g);
}

int		main(int argc, char *argv[])
{
	int		g;
	int		(*op_ab[3])(t_stack *a, t_stack *b, int);
	int		(*op_x[3])(t_stack *s, int);
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	real_mode(0);
	a.first = 0;
	b.first = 0;
	fill_stack(argc, argv, &a, 1);
	if (!(a.first))
		return (0);
	ft_memcpy(op_ab, (void *[]){ss, rr, rrr}, 3 * sizeof(void *));
	ft_memcpy(op_x, (void *[]){sx, rx, rrx}, 3 * sizeof(void *));
	g = 1;
	while (g == 1)
		g = exec(&a, &b, op_ab, op_x);
	if (g == -1)
		error();
	write(1, (is_sorted(&a, 1) && !b.first) ? "OK\n" : "KO\n", 3);
	return (empty_stacks(&a, &b));
}
