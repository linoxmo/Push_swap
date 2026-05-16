/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <tmagoudi@learner42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:07:48 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/16 15:45:11 by tmagoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_normalise(t_stack *a) {
  int index;
  t_list *temp;
  t_list *temp_1;

  temp = a->top;

  while (temp) {
    index = 0;
    temp_1 = a->top;
    while (temp_1) {
      if (temp->content > temp_1->content)
        index++;
      temp_1 = temp_1->next;
    }
    temp->index = index;
    temp = temp->next;
  }

  return;
}

void pt_index(t_stack *a) {
  while (a->top) {
    printf("%d\n", a->top->index);
    a->top = a->top->next;
  }
}

int ft_sqrt(int op) {
  int i;

  i = 0;
  while (i * i < op)
    i++;
  return (i);
}

void ft_medium(t_stack *a, t_stack *b) {
  int chunk_size;
  int nb_chunk;
  t_list temp;

  temp = 
  chunk_size = ft_sqrt(a->size);
  nb_chunk = (a->size + (chunk_size - 1)) / chunk_size;
  ft_normalise(a);


  return;
}

// int main() {

//   int i;

//   i = 15;

//   printf("%d\n", ft_sqrt(i));
//   printf("%d\n", (i + ft_sqrt(i) - 1) / ft_sqrt(i));
// }
