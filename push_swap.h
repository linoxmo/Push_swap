/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <ttmagoudi@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:39:53 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/10 16:35:32 by rfeghali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_list
{
	int	content;
	struct  s_list *next;
}		t_list;

/* stack operations */
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rs(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrs(t_list **a, t_list **b);

/* list utils */
void 	ft_lstadd_back(t_list **lst, t_list *new);

/* general utils */
int		ft_atoi(char *str);

#endif
