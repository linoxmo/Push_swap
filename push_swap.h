/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <ttmagoudi@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:39:53 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/15 12:41:19 by rfeghali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct	s_list
{
	int				content;
	int				index;
	struct  s_list	*next;
}		t_list;

typedef struct s_stack
{
	t_list	*top;
	int		size;
}	t_stack;

typedef struct s_operation
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_operation;

/* stack operations */
void		pa(t_stack *a, t_stack *b, t_operation *ops);
void		pb(t_stack *a, t_stack *b, t_operation *ops);
void		sa(t_stack *a, t_operation *ops);
void		sb(t_stack *b, t_operation *ops);
void		ss(t_stack *a, t_stack *b, t_operation *ops);
void		ra(t_stack *a, t_operation *ops);
void		rb(t_stack *b, t_operation *ops);
void		rr(t_stack *a, t_stack *b, t_operation *ops);
void		rra(t_stack *a, t_operation *ops);
void		rrb(t_stack *b, t_operation *ops);
void		rrr(t_stack *a, t_stack *b, t_operation *ops);

/* list utils */
t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
t_stack		*init_stack(void);
void		free_stack(t_stack *stack);
int			stack_min(t_stack *stack);
int			stack_max(t_stack *stack);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			get_position(t_stack *stack, int value);
int			get_position_idx(t_stack *stack, int target);

/* general utils */
long		ft_atol(const char *nptr);
void		print_stack(t_stack *stack);

/* init function */
t_operation	*init_ops(void);
void		init_index(t_stack *a);

/*sort algos */
void		simple_sort(t_stack *a, t_stack *b, t_operation *ops);
int			is_sorted(t_stack *a);
void		radix_sort(t_stack *a, t_stack *b, t_operation *ops);
void		chunk_sort(t_stack *a, t_stack *b, t_operation *ops);

#endif
