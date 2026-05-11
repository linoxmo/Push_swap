#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_list	*current;
	t_list	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}


int	stack_min(t_stack *stack)
{
	t_list	*current;
	int		min;

	if (!stack || stack->size == 0)
		return (0);
	current = stack->top;
	min = current->content;
	while (current)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	return (min);
}

int	stack_max(t_stack *stack)
{
	t_list	*current;
	int		max;

	if (!stack || stack->size == 0)
		return (0);
	current = stack->top;
	max = current->content;
	while (current)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	return (max);
}

int	get_position(t_stack *stack, int content)
{
	t_list	*current;
	int		pos;

	pos = 0;
	current = stack->top;
	while (current)
	{
		if (current->content == content)
			return (pos);
		pos++;
		current = current->next;
	}
	return (-1);
}
