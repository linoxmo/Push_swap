#include "push_swap.h"

static int	ft_sqrt(int x)
{
	int	i;

	i = 0;
	while (i * i < x)
		i++;
	return (i);
}


static void	move_to_top_b(t_stack *b, int pos, t_operation *ops)
{
	if (pos <= b->size / 2)
	{
		while (pos-- > 0)
			rb(b, ops);
	}
	else
	{
		pos = b->size - pos;
		while (pos-- > 0)
			rrb(b, ops);
	}
}

static void	push_chunks(t_stack *a, t_stack *b, t_operation *ops)
{
	int	chunk_size;
	int	limit;
	int	pushed;

	chunk_size = (int)ft_sqrt(a->size) + 1;
	limit = chunk_size;
	pushed = 0;
	while (a->size)
	{
		if (a->top->index < limit)
		{
			pb(a, b, ops);
			pushed++;
			if (b->top->index < (limit - chunk_size / 2))
				rb(b, ops);
			if (pushed >= limit)
				limit += chunk_size;
		}
		else
			ra(a, ops);
	}
}

void	chunk_sort(t_stack *a, t_stack *b, t_operation *ops)
{
	int	pos;

	init_index(a);
	push_chunks(a, b, ops);
	while (b->size > 0)
	{
		pos = get_position_idx(b, b->size - 1);
		move_to_top_b(b, pos, ops);
		pa(a, b, ops);
	}
}
