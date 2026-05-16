#include "push_swap.h"

int	compute_disorder(t_stack *a)
{
	t_list	*i_node;
	t_list	*j_node;
	int		mistakes;
	int		total_pairs;

	if (!a || a->size <= 1)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	i_node = a->top;
	while (i_node)
	{
		j_node = i_node->next;
		while (j_node)
		{
			total_pairs++;
			if (i_node->content > j_node->content)
				mistakes++;
			j_node = j_node->next;
		}
		i_node = i_node->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((mistakes * 100) / total_pairs);
}
