/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# define OP (char *[]){"sa", "sb", "ra", "rb", "rra", "rrb"}
# define SMALL_STACK_LEN 20

typedef	struct	s_intl
{
	int				n;
	struct s_intl	*next;
}				t_intl;

typedef	struct	s_array
{
	int				len;
	int				*data;
}				t_array;

typedef	struct	s_stack
{
	t_intl *first;
}				t_stack;

int				ft_atoi_check(const char *str);
void			*pr_malloc(size_t n);
char			**while_char(char *str, char **words, int save, int w);
char			**ft_split_arg(char *str);
int				real_mode(int x);
void			arr_sort(int *tab, unsigned int size);
int				sort_large_stack(t_stack **s, t_array arr,
	int argc, char *argv[]);
int				sort_small_stack(t_stack *a, t_stack *b);
int				is_sorted(t_stack *s, int order);
int				still(t_intl *t, int x, int y);
void			rotate_n(t_stack *s, int n, int *op, int ab);
int				pop(t_stack *stack);
void			push(t_stack *stack, int n);
int				empty_stacks(t_stack *a, t_stack *b);
int				stlen(t_intl *t);
int				maxstack(t_stack *s);
int				id_minstack(t_stack *s);
void			print_stack(t_stack *s);
void			reset_stacks(t_stack *a, t_stack *b, int argc, char *argv[]);
int				fill_stack(int argc, char *argv[], t_stack *stack, int inv);
void			error();
int				sx(t_stack *s, int ab);
int				px(t_stack *a, t_stack *b, int ab);
int				rx(t_stack *s, int ab);
int				rrx(t_stack *s, int ab);
int				rr(t_stack *a, t_stack *b, int ab);
int				ss(t_stack *a, t_stack *b, int ab);
int				rrr(t_stack *a, t_stack *b, int ab);
#endif
