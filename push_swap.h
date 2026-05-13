/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <ttmagoudi@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:39:53 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/13 18:16:56 by tmagoudi         ###   ########.fr       */
/*   Updated: 2026/05/12 15:47:04 by tmagoudi         ###   ########.fr       */
/*   Updated: 2026/05/10 15:59:01 by tmagoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list {
  int content;
  int index;
  struct s_list *next;
} t_list;

typedef struct s_stack {
  t_list *top;
  int size;
} t_stack;

typedef struct s_operation {
  int sa;
  int sb;
  int ss;
  int pa;
  int pb;
  int ra;
  int rb;
  int rr;
  int rra;
  int rrb;
  int rrr;
  int total;
} t_operation;

/* stack operations */
void pa(t_stack *a, t_stack *b, t_operation *ops);
void pb(t_stack *a, t_stack *b, t_operation *ops);
void sa(t_stack *a, t_operation *ops);
void sb(t_stack *b, t_operation *ops);
void ss(t_stack *a, t_stack *b, t_operation *ops);
void ra(t_stack *a, t_operation *ops);
void rb(t_stack *b, t_operation *ops);
void rr(t_stack *a, t_stack *b, t_operation *ops);
void rra(t_stack *a, t_operation *ops);
void rrb(t_stack *b, t_operation *ops);
void rrr(t_stack *a, t_stack *b, t_operation *ops);

/* list utils */
void ft_lstadd_back(t_list **lst, t_list *new);
t_list *ft_lstnew(int content);
t_list *ft_lstlast(t_list *lst);
t_stack *init_stack(void);
void free_stack(t_stack *stack);
int stack_min(t_stack *stack);
int stack_max(t_stack *stack);
int get_position(t_stack *stack, int value);

/* general utils */
long ft_atol(const char *nptr);
int ft_atoi(char *str);
void print_stack(t_stack *stack);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
char **ft_split(char const *s, char c);
void free_split(char **res, int m);
size_t ft_strlen(char const *s);

/* init function */
t_operation *init_ops(void);

/*sort algos */
void simple_sort(t_stack *a, t_stack *b, t_operation *ops);
void ft_simple_1(t_stack *a, t_stack *b, t_operation *ops);
int is_sorted(t_stack *a);
int ft_atoi(char *str);
t_list *ft_lstnew(int content);
#endif
