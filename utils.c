#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_list	*current;

	if (!a || a->size <= 1)
		return (1);
	current = a->top;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	get_position_idx(t_stack *stack, int target)
{
	t_list	*cur;
	int		pos;

	cur = stack->top;
	pos = 0;
	while (cur)
	{
		if (cur->index == target)
			return (pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}
