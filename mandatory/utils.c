/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouarr <ielouarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:40:55 by ielouarr          #+#    #+#             */
/*   Updated: 2025/02/06 16:04:09 by ielouarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_error_message(char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		write (2, &message[i], 1);
		i++;
	}
	write (2, "\n", 1);
	exit(1);
	return (-1);
}

void	ft_duplicate(t_list *lst)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp1 = lst;
	ft_indexing(lst);
	while (tmp1)
	{
		tmp = tmp1->next;
		while (tmp)
		{
			if (tmp1->data == tmp->data)
				ft_error_message("Error");
			tmp = tmp-> next;
		}
		tmp1 = tmp1->next;
	}
}

int	is_sort(t_list **lst)
{
	t_list	*iter;

	iter = (*lst);
	while (iter)
	{
		if (iter->next != NULL)
		{
			if (iter->data > iter->next->data)
				return (1);
		}
		iter = iter->next;
	}
	return (0);
}

t_list	*get_min_number(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (lst->data > tmp->data)
			lst = tmp;
		tmp = tmp->next;
	}
	return (lst);
}

t_list	*get_max_number(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (lst->data < tmp->data)
			lst = tmp;
		tmp = tmp->next;
	}
	return (lst);
}
