#include "push_swap.h"

static void	push(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (!from || !to || !*from)
		return ;
	tmp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = tmp;
}

void	pa(t_list **a, t_list **b)
{
	push(b, a);
}

void	pb(t_list **a, t_list **b)
{
	push(a, b);
}

// int main(void)
// {
// 	t_list	*a;
// 	t_list	*b;
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
