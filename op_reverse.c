#include "push_swap.h"

static void reverse_rotate(t_stack *lst)
{
	t_list	*prev;
	t_list	*last;

	if (!lst || !lst->top || !lst->top->next)
		return ;
	prev = lst->top;
	while (prev->next->next != NULL)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = lst->top;
	lst->top = last;
}

void	rra(t_stack *a, t_operation *ops)
{
	reverse_rotate(a);
	ops->rra++;
}

void	rrb(t_stack *b, t_operation *ops)
{
	reverse_rotate(b);
	ops->rrb++;
}

void	rrr(t_stack *a, t_stack *b, t_operation *ops)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ops->rrr++;
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
// 	rrr(&a, &b);
// 	printf("the stacks after\n");
// 	ft_lstprint(a);
// 	printf("\n");
// 	ft_lstprint(b);
// }
