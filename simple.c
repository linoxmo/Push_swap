#include "push_swap.h"

void	simple_sort(t_stack *a, t_stack *b, t_operation *ops)
{
	int		min;
	int		pos;

	while (a->size)
	{
		min = stack_min(a);
		pos = get_position(a, min);
		while (pos-- > 0)
			ra(a, ops);
		pb(a, b, ops);
	}
	while (b->size > 0)
		pa(a, b, ops);
}
