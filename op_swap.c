#include "push_swap.h"

static void	swap(t_stack *lst)
{
	t_list	*node;

	if (!lst || !lst->top || !lst->top->next)
		return ;
	node = lst->top->next;
	lst->top->next = node->next;
	node->next = lst->top;
	lst->top = node;
}

void	sa(t_stack *a)
{
	swap(a);
}

void	sb(t_stack *b)
{
	swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

// int main(void)
// {
// 	t_list	*a;
// 	int		i;
// 	int		len;
//
// 	len = 5;
// 	i = 0;
// 	while (i < len)
// 		ft_lstadd_back(&a, ft_lstnew(i++));
// 	sa(&a);
// 	ft_lstprint(a);
// }
