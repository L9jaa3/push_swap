#include "checker.h"

void	sa(t_list **a)
{
	t_list	*tmp;
	t_list	*prev;

	if (!a || !*a)
		return ;
	if (ft_lstsize(*a) < 2)
		return ;
	tmp = *a;
	prev = (*a)->next;
	tmp->next = prev->next;
	prev->next = tmp;
	(*a) = prev;
	write(1, "sa\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (ft_lstsize(*b) < 1)
		return ;
	tmp = *b;
	*b = tmp->next;
	tmp->next = (*a);
	*a = tmp;
	write(1, "pa\n", 3);
}

void	ra(t_list **a, int i)
{
	t_list	*curr;
	t_list	*prev;
	t_list	*tmp;

	if (ft_lstsize(*a) < 2)
		return ;
	tmp = *a;
	curr = *a;
	prev = (*a)->next;
	while (curr->next)
		curr = curr->next;
	curr->next = tmp;
	tmp->next = NULL;
	(*a) = prev;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rra(t_list **a, int i)
{
	t_list	*curr;
	t_list	*prev;

	if (ft_lstsize(*a) < 2)
		return ;
	curr = *a;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	curr->next = *a;
	prev->next = NULL;
	(*a) = curr;
	if (i == 1)
		write(1, "rra\n", 4);
}


