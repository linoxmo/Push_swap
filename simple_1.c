/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <tmagoudi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:16:56 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/13 14:19:02 by tmagoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_simple_1(t_stack *a, t_stack *b) {
  int i;
  int min;
  int pos;
  t_list *temp;

  i = 0;
  min = a->top->content;
  pos = 0;
  temp = a->top;
  while (temp) {
    while (i < a->size) {
      temp = temp->next;
      if (temp->content <= min) {
        min = temp->content;
        pos = i;
      }
      i++;
    }
    i = 0;
    while (i < pos) {
      ra(a);
      i++;
    }
    pb(a, b);
  }
  return (a);
}
