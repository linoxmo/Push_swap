#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_list	*current;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		printf("value : %d\n", current->content);
		current = current->next;
	}
}
