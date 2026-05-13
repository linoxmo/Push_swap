#include "push_swap.h"

static int	find_insert_position(t_stack *a, int content)
{
	t_list	*curr;
	t_list	*next;
	int		pos;
	int		min;
	int		max;

	if (!a || !a->top)
		return (0);
	min = stack_min(a);
	max = stack_max(a);
	if (content < min || content > max)
		return (get_position(a, min));
	curr = a->top;
	pos = 0;
	while (curr->next)
	{
		next = curr->next;
		if (curr->content < content && content < next->content)
			return (pos + 1);
		curr = curr->next;
		pos++;
	}
	return (0);
}

// return rotation cost to bring a position on top
static int	get_rotation_cost(int size, int pos)
{
	if (pos <= size / 2)
		return (pos);
	return (size - pos);
}

// Rotates in cheapest direction
static void	rotate_stack_to_top(t_stack *stack,
	int pos, char stack_name, t_operation *ops)
{
	if (pos <= stack->size / 2)
	{
		while (pos-- > 0)
		{
			if (stack_name == 'a')
				ra(stack, ops);
			else
				rb(stack, ops);
		}
	}
	else
	{
		pos = stack->size - pos;
		while (pos-- > 0)
		{
			if (stack_name == 'a')
				rra(stack, ops);
			else
				rrb(stack, ops);
		}
	}
}

static void	sort_three(t_stack *a, t_operation *ops)
{
	int	first;
	int	second;
	int	third;

	first = a->top->content;
	second = a->top->next->content;
	third = a->top->next->next->content;
	if (first > second && second < third && first < third)
		sa(a, ops);
	else if (first > second && second > third)
	{
		sa(a, ops);
		rra(a, ops);
	}
	else if (first > second && second < third && first > third)
		ra(a, ops);
	else if (first < second && second > third && first < third)
	{
		sa(a, ops);
		ra(a, ops);
	}
	else if (first < second && second > third && first > third)
		rra(a, ops);
}

static void	find_cheapest_move(t_stack *a, t_stack *b,
	int *best_b_pos, int *best_a_pos)
{
	t_list	*curr;
	int		b_pos;
	int		a_pos;
	int		cost;
	int		best_cost;

	curr = b->top;
	b_pos = 0;
	best_cost = INT_MAX;
	while (curr)
	{
		a_pos = find_insert_position(a, curr->content);
		cost = get_rotation_cost(b->size, b_pos)
			+ get_rotation_cost(a->size, a_pos);
		if (cost < best_cost)
		{
			best_cost = cost;
			*best_b_pos = b_pos;
			*best_a_pos = a_pos;
		}
		curr = curr->next;
		b_pos++;
	}
}

static void	final_rotate(t_stack *a, t_operation *ops)
{
	int	min_pos;

	min_pos = get_position(a, stack_min(a));
	if (min_pos <= a->size / 2)
		while (min_pos-- > 0)
			ra(a, ops);
	else
	{
		min_pos = a->size - min_pos;
		while (min_pos-- > 0)
			rra(a, ops);
	}
}

void	simple_sort(t_stack *a, t_stack *b, t_operation *ops)
{
	int	best_b_pos;
	int	best_a_pos;

	if (!a || is_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (a->top->content > a->top->next->content)
			sa(a, ops);
		return ;
	}
	if (a->size == 3)
		return (sort_three(a, ops));
	while (a->size > 3)
		pb(a, b, ops);
	sort_three(a, ops);
	while (b->size > 0)
	{
		find_cheapest_move(a, b, &best_b_pos, &best_a_pos);
		rotate_stack_to_top(a, best_a_pos, 'a', ops);
		rotate_stack_to_top(b, best_b_pos, 'b', ops);
		pa(a, b, ops);
	}
	final_rotate(a, ops);
}
