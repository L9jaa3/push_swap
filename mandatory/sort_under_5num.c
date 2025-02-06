/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_5num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouarr <ielouarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:35:26 by ielouarr          #+#    #+#             */
/*   Updated: 2025/02/06 16:05:18 by ielouarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_five_or_less(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		ft_sort_two(a);
	else if (ft_lstsize(*a) == 3)
		ft_sort_three(a);
	else if (ft_lstsize(*a) == 4)
		ft_sort_four(a, b);
	else if (ft_lstsize(*a) == 5)
		ft_sort_five(a, b);
	ft_lstclear(a);
	return ;
}

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
