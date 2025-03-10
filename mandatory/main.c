/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouarr <ielouarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:36:20 by ielouarr          #+#    #+#             */
/*   Updated: 2025/02/06 15:47:46 by ielouarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

void	ft_indexing(t_list *lst)
{
	t_list	*tmp;
	t_list	*tmpx;
	int		i;

	tmpx = lst;
	while (tmpx)
	{
		i = 0;
		tmp = lst;
		while (tmp)
		{
			if (tmp->data < tmpx->data)
				i++;
			tmp = tmp->next;
		}
		tmpx->indx = i;
		tmpx = tmpx->next;
	}
}

int	max_position(t_list *lst)
{
	t_list	*tmp;
	t_list	*max;

	tmp = lst;
	max = tmp;
	while (tmp)
	{
		if (tmp->data > max->data)
			max = tmp;
		tmp = tmp->next;
	}
	return (max->position);
}

void	mark_position(t_list **stack)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = (*stack);
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_list	*s_a;
	t_list	*s_b;

	s_a = NULL;
	s_b = NULL;
	if (ac == 1)
		return (0);
	ft_parcing(&s_a, av);
	if (is_sort(&s_a))
	{
		ft_sort(&s_a, &s_b, 0, 0);
		ft_sort_b(&s_a, &s_b, 0);
	}
	ft_lstclear(&s_a);
}
