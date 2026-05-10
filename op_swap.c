#include "push_swap.h"

static void	swap(t_list **lst)
{
	t_list	*node;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	node = (*lst)->next;
	(*lst)->next = node->next;
	node->next = (*lst);
	(*lst) = node;
}

void	sa(t_list **a)
{
	swap(a);
}

void	sb(t_list **b)
{
	swap(b);
}

void	ss(t_list **a, t_list **b)
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
