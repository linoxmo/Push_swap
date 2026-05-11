/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <ttmagoudi@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:39:53 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/11 13:41:24 by rfeghali         ###   ########.fr       */
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
	int	content;
	struct  s_list *next;
}		t_list;

typedef struct s_stack
{
	t_list	*top;
	int		size;
}	t_stack;

/* stack operations */
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* list utils */
void 	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
t_stack	*init_stack(void);
void	free_stack(t_stack *stack);
int		stack_min(t_stack *stack);
int		stack_max(t_stack *stack);
int		get_position(t_stack *stack, int value);

/* general utils */
long	ft_atol(const char *nptr);
int		ft_atoi(char *str);
void	print_stack(t_stack *stack);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);
void	free_split(char **res, int m);
size_t	ft_strlen(char const *s);

/*sort algos */
void	simple_sort(t_stack *a, t_stack *b);
int		is_sorted(t_stack *a);

#endif
