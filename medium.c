/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <tmagoudi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:07:48 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/15 15:30:55 by tmagoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_sqrt(int op)
{
	int	i;

	i = 0;
	while (i * i < op)
		i++;
	if (i*i == op)
		return (i);
	else
		return (i - 1);
}


void	ft_medium(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	nb_chunk;

	chunk_size = ft_sqrt(a->size);
	nb_chunk = (a->size + (chunk_size -1)) / chunk_size;
	return ;

}


int main()
{

	int	i;

	i = 15;

	printf("%d\n", ft_sqrt(i)); 
	printf("%d\n", (i + ft_sqrt(i) -1) / ft_sqrt(i));
}
