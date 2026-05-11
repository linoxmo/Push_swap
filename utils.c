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
