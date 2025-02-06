/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouarr <ielouarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:36:44 by ielouarr          #+#    #+#             */
/*   Updated: 2025/02/06 16:05:06 by ielouarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	detect_bad_distribution(t_list *stack)
{
	t_list	*ptr;
	int		diff_count;
	int		diff;
	int		size;

	size = ft_lstsize(stack);
	diff_count = 0;
	ptr = stack;
	while (ptr && ptr->next)
	{
		diff = ptr->indx - ptr->next->indx;
		if (diff == 2 || diff == 3 || diff == 4)
			diff_count++;
		ptr = ptr->next;
	}
	if (diff_count * 10 >= size * 6)
		return (3);
	return (0);
}

static void	ft_sort_setup(t_list **a, t_list **b, int *x)
{
	if (ft_lstsize(*a) <= 5)
	{
		ft_sort_five_or_less(a, b);
		return ;
	}
	if (ft_lstsize(*a) <= 100)
		*x = 16;
	else
		*x = 36;
}

static void	ft_sort_process(t_list **a, t_list **b, int i, int x)
{
	t_list	*tmp;
	int		bad_distribution;

	bad_distribution = detect_bad_distribution(*a);
	while (*a)
	{
		tmp = *a;
		if (tmp->indx <= i)
		{
			pb(a, b);
			i++;
		}
		else if (tmp->indx <= i + x)
		{
			pb(a, b);
			rb(b, 1);
			i++;
		}
		else if (bad_distribution)
			rra(a, 1);
		else
			ra(a, 1);
	}
}

void	ft_sort(t_list **a, t_list **b, int i, int x)
{
	ft_sort_setup(a, b, &x);
	if (!(*a))
		return ;
	ft_sort_process(a, b, i, x);
}

void	ft_sort_b(t_list **a, t_list **b, int size)
{
	int	max;

	size = ft_lstsize(*b);
	while (size)
	{
		mark_position(b);
		max = max_position(*b);
		if (max < size / 2)
		{
			while ((*b)->position != max)
				rb(b, 1);
		}
		else
		{
			while ((*b)->position != max)
				rrb(b, 1);
		}
		pa(a, b);
		size--;
	}
}
