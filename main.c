#include "push_swap.h"

typedef struct	s_info
{
	int	bench;
	int	strategy;
	int	arg_idx;
}	t_info;

int	has_duplicate(t_stack *a)
{
	t_list	*i_node;
	t_list	*j_node;

	i_node = a->top;
	while (i_node->next)
	{
		j_node = i_node->next;
		while (j_node)
		{
			if (i_node->content == j_node->content)
				return (0);
			j_node = j_node->next;
		}
		i_node = i_node->next;
	}
	return (1);
}

int	is_valid(char **av, t_info *info)
{
	int	i;
	i = info->arg_idx;
	while (av[i])
	{
		if (ft_atol(av[i]) < INT_MIN || ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	parse_strategy(char *s, t_info *info)
{
	if (ft_strcmp(s, "--simple") == 0)
		info->strategy = 0;
	else if (ft_strcmp(s, "--medium") == 0)
		info->strategy = 1;
	else if (ft_strcmp(s, "--hard") == 0)
		info->strategy = 2;
	else if (ft_strcmp(s, "--adaptative") == 0)
		info->strategy = 3;
	else
		return (0);
	return (1);
}

int	parse_flag(char **av , t_info	*info)
{
	info->arg_idx = 1;
	if (av[1] && av[1][0] == '-' && av[1][1] == '-')
	{
		if (ft_strcmp(av[1], "--bench") == 0)
			info->bench = 1;
		else if (!parse_strategy(av[1], info))
			return (0);
		info->arg_idx = 2;
	}
	if (av[2] && av[2][0] == '-' && av[2][1] == '-')
	{
		if (!parse_strategy(av[2], info))
			return (0);
		info->arg_idx = 3;
	}
	return (1);	
}

int	parse_arg(t_stack *a, int ac, char **av, t_info* info)
{
	int	i;
	if (ac < 2)
		return (0);
	if (!parse_flag(av++, info))
		return (0);
	i = info->arg_idx;
	if (!is_valid(av + i, info))
		return (0);
	while (av[i])
	{
		ft_lstadd_back(&a->top, ft_lstnew((int)ft_atol(av[i]))); 
		a->size++;
		i++;
	}
	if (!has_duplicate(a))
		return (0);
	return (1);
}

void	adaptative_sort(t_stack *a, t_stack *b, t_operation *ops)
{
	int	disorder;

	disorder = compute_disorder(a);
	if (disorder < 20)
		simple_sort(a, b, ops);
	else if (disorder > 50)
		complex_sort(a, b, ops);
	else
		medium_sort(a, b, ops);
}

void	choose_strategy(t_stack *a, t_stack *b, t_operation *ops, t_info *info)
{
	if (info->strategy == 0)
		simple_sort(a, b, ops);
	else if (info->strategy == 1)
		medium_sort(a, b, ops);
	else if (info->strategy == 2)
		complex_sort(a, b, ops);
	else
		adaptative_sort(a, b, ops);
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	int			i;
	t_operation	*ops;
	t_info		*info;

	a = init_stack();
	b = init_stack();
	ops = init_ops();
	if (!a || !b || !ops)
		return (write(1, "Error\n", 6), 1);
	if (!parse_arg(a, ac, av, info)) // FREE
		return (write(1, "Error\n", 6), 1);
	// i = 1;
	// while (i < ac)
	// {
	// 	ft_lstadd_back(&a->top, ft_lstnew((int)ft_atol(av[i])));
	// 	a->size++;
	// 	i++;
	// }
	simple_sort(a, b, ops);
	print_stack(a);
	print_stack(b);
	printf("\n%d\n", ops->total);
	return (free_stack(a), free_stack(b), free(ops), 0);
}
