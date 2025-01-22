#include "push_swap.h"

void	ft_sort_two(t_list **lst)
{
	if ((*lst)->data > (*lst)->next->data)
		sa(lst);
	return ;
}

void	ft_sort_three(t_list **lst)
{
	t_list	*max;

	if (is_sort(lst))
	{
		max = get_max_number(*lst);
		if (max->data == (*lst)->data)
			ra(lst, 1);
		else if (max->data == (*lst)->next->data)
			rra(lst, 1);
		if ((*lst)->data > (*lst)->next->data)
			sa(lst);
	}
	return ;
}

void	ft_sort_four(t_list **a, t_list **b)
{
	t_list	*min;

	if (is_sort(a))
	{
		min = get_min_number(*a);
		while (1)
		{
			if (min->data != (*a)->data)
				rra(a, 1);
			else
				break ;
		}
		pb(a, b);
		ft_sort_three(a);
		pa(a, b);
	}
	return ;
}

void	ft_sort_five(t_list **a, t_list **b)
{
	t_list	*min;

	if (is_sort(a))
	{
		min = get_min_number(*a);
		while (1)
		{
			if (min == (*a)->next)
				ra(a, 1);
			else if (min->data != (*a)->data)
				rra(a, 1);
			else
				break ;
		}
		pb(a, b);
		ft_sort_four(a, b);
		pa(a, b);
		return ;
	}
	return ;
}

