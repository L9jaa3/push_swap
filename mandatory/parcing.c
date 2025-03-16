/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouarr <ielouarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:36:31 by ielouarr          #+#    #+#             */
/*   Updated: 2025/02/06 16:04:43 by ielouarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_leak(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_parcing(t_list **nbr, char **av)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (ft_strlen(av[i]) == 0 || check_digit(av[i]) == 0)
			ft_error_message("Error", nbr);
		str = ft_split(av[i], ' ');
		if (!str)
			exit(1);
		while (str[j])
		{
			ft_lstadd_back(nbr, ft_lstnew(ft_atoi(str, str[j], *nbr)));
			ft_duplicate(*nbr, str);
			j++;
		}
		ft_free_leak(str);
		i++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
