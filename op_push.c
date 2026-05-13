#include "push_swap.h"

static void	push(t_stack *from, t_stack *to)
{
	t_list	*tmp;

	if (!from || !to || !from->top)
		return ;
	tmp = from->top->next;
	from->top->next = to->top;
	to->top = from->top;
	from->top = tmp;
	from->size--;
	to->size++;
}

void	pa(t_stack *a, t_stack *b, t_operation *ops)
{
	push(b, a);
	ops->pa++;
	ops->total++;
}

void	pb(t_stack *a, t_stack *b, t_operation *ops)
{
	push(a, b);
	ops->pb++;
	ops->total++;
}

// int main(void)
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	int		i;
// 	int		len;
//
// 	len = 5;
// 	i = 0;
// 	while (i < len)
// 		ft_lstadd_back(&a, ft_lstnew(i++));
// 	while (i < len + 5)
// 		ft_lstadd_back(&b, ft_lstnew(i++));
// 	printf("the stacks before\n");
// 	ft_lstprint(a);
// 	printf("\n");
// 	ft_lstprint(b);
// 	pa(&a, &b);
// 	printf("the stacks after\n");
// 	ft_lstprint(a);
// 	printf("\n");
// 	ft_lstprint(b);
// }
