/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <ttmagoudi@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:39:53 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/09 18:09:19 by tmagoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typdef struct	s_list
{
	int	content;
	struct  s_list *next;
}		t_list;

void 	ft_lstadd_back(t_list **lst, t_list *new);
int	ft_atoi(char *str);

#endif
