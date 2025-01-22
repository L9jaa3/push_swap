#include "checker.h"

void	sb(t_list **b)
{
	t_list	*tmp;
	t_list	*prev;

	if (!b || !*b)
		return ;
	if (ft_lstsize(*b) < 2)
		return ;
	tmp = *b;
	prev = (*b)->next;
	tmp->next = prev->next;
	prev->next = tmp;
	(*b) = prev;
	write(1, "sb\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (ft_lstsize(*a) < 1)
		return ;
	tmp = *a;
	tmp2 = *b;
	*a = (*a)->next;
	tmp->next = tmp2;
	*b = tmp;
	write(1, "pb\n", 3);
}

void	rb(t_list **b, int i)
{
	t_list	*curr;
	t_list	*prev;
	t_list	*tmp;

	if (ft_lstsize(*b) < 2)
		return ;
	tmp = *b;
	curr = *b;
	prev = (*b)->next;
	while (curr->next)
		curr = curr->next;
	curr->next = tmp;
	tmp->next = NULL;
	(*b) = prev;
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rrb(t_list **b, int i)
{
	t_list	*curr;
	t_list	*prev;

	if (ft_lstsize(*b) < 2)
		return ;
	curr = *b;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	curr->next = *b;
	prev->next = NULL;
	(*b) = curr;
	if (i == 1)
		write(1, "rrb\n", 4);
}


