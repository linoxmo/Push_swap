/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_general.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagoudi <ttmagoudi@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:50:12 by tmagoudi          #+#    #+#             */
/*   Updated: 2026/05/09 17:51:07 by tmagoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_atoi(char *str)
{
        int     num;
        int     sign;

        num = 0;
        sign = 1;
        while (*str && (*str >= 9 && *str <= 13))
                str++;
        if (*str && (*str == '-' || *str == '+'))
        {
                if (*str == '-')
                        sign = -1;
                str++;
        }
        while (*str && *str >= '0' && *str <= '9')
        {
                num = num * 10 + (*str - '0');
                str++;
        }
        return (sign * num);
}
