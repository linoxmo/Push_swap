#include "push_swap.h"

t_operation	*init_ops(void)
{
	t_operation	*ops;

	ops = malloc(sizeof(t_operation));
	ops->sa = 0;
	ops->sb = 0;
	ops->ss = 0;
	ops->pa = 0;
	ops->pb = 0;
	ops->ra = 0;
	ops->rb = 0;
	ops->rr = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
	ops->total = 0;
	return (ops);
}

void	init_index(t_stack *a)
{
	t_list	*i;
	t_list	*j;
	int		index;

	i = a->top;
	while (i)
	{
		index = 0;
		j = a->top;
		while (j)
		{
			if (j->content < i->content)
				index++;
			j = j->next;
		}
		i->index = index;
		i = i->next;
	}
}
