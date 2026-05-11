#include "push_swap.h"

static void	rotate(t_stack *lst)
{
	t_list	*tmp;

	if (!lst || !lst->top || !lst->top->next)
		return ;
	tmp = ft_lstlast(lst->top);
	tmp->next = lst->top;
	lst->top = lst->top->next;
	tmp->next->next = NULL;
}

void	ra(t_stack *a)
{
	rotate(a);
}

void	rb(t_stack *b)
{
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
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
// 	rr(&a, &b);
// 	printf("the stacks after\n");
// 	ft_lstprint(a);
// 	printf("\n");
// 	ft_lstprint(b);
// }
