#include "push_swap.h"

static int	get_max_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = a->size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b, t_operation *ops)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	init_index(a);
	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = a->size;
		while (j < size)
		{
			if (((a->top->index >> i) & 1) == 1)
				ra(a, ops);
			else
				pb(a, b, ops);
			j++;
		}
		while (b->size > 0)
			pa(a, b, ops);
		i++;
	}
}
