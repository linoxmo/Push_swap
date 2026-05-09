#include "push_swap.h"

void	sa(t_list **a)
{
	t_list	*node;

	if (!a || !*a || !(*a)->next)
		return ;
	node = (*a)->next;
	(*a)->next = node->next;
	node->next = (*a);
	(*a) = node;
}

int main(void)
{
	t_list	*a;
	int		i;
	int		len;

	len = 5;
	i = 0;
	while (i < len)
		ft_lstadd_back(&a, ft_lstnew(i++));
	sa(&a);
	ft_lstprint(a);
}
