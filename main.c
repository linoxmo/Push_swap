/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <ttmagoudi@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:26:47 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/09 17:57:18 by tmagoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	main(int ac, char **av)
{
	int	i;

	if (ac < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	while(av[i])
	{
		printf("%d,\n",ft_atoi(av[i]));
		i++;
	} 
	return(1);
}
