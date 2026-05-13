/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <tmagoudi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:16:56 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/13 19:43:20 by tmagoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_simple_1(t_stack *a, t_stack *b, t_operation *ops) {
  int i;
  int min;
  int pos;
  t_list *temp;

  pos = 0;
  min = a->top->content;
  while (a->size) 
  {
    temp = a->top;
    min = temp->content;
    i = 0;
    while (temp) 
    {
	if (temp->content < min) 
	{
        min = temp->content;
        pos = i;
      }
      temp = temp->next;
      i++;
    }
    while (pos-- > 0) 
    {
      ra(a, ops);
    }
    pb(a, b, ops);
  }
  while (b->size > 0)
    pa(a, b, ops);
  return;
}
