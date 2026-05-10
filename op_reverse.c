#include "push_swap.h"

static void reverse_rotate(t_list **lst)
{
	t_list	*prev;
	t_list	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	prev = *lst;
	while (prev->next->next != NULL)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *lst;
	*lst = last;
}

void	rra(t_list **a)
{
	reverse_rotate(a);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
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
// 	rrr(&a, &b);
// 	printf("the stacks after\n");
// 	ft_lstprint(a);
// 	printf("\n");
// 	ft_lstprint(b);
// }
