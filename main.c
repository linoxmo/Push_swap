#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	int			i;
	t_operation	*ops;

	if (ac < 2)
		return (write(1, "Error\n", 6), 1);
	a = init_stack();
	b = init_stack();
	ops = init_ops();
	if (!a || !b || !ops)
		return (write(1, "Error\n", 6), 1);
	i = 1;
	while (i < ac)
	{
		ft_lstadd_back(&a->top, ft_lstnew((int)ft_atol(av[i])));
		a->size++;
		i++;
	}
	simple_sort(a, b);
	print_stack(a);
	print_stack(b);
	free_stack(a);
	free_stack(b);
	return (0);
}
