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

void	ft_free_list(t_list **nbr)
{
	t_list	*tmp;

	while (*nbr)
	{
		tmp = (*nbr)->next;
		free(*nbr);
		*nbr = tmp;
	}
}

static void	validate_result(long res, int sign, char c, t_list **nbr)
{
	if ((res * sign > 2147483647) || (res * sign < -2147483648)
		|| (c < '0' || c > '9'))
	{
		ft_free_list(nbr);
		ft_error_message("Error");
	}
}


static int	ft_atoi(const char *str, t_list **nbr)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	if (str[i] == '\0')
	{
		ft_free_list(nbr);
		ft_error_message("Error");
	}
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		validate_result(res, sign, str[i], nbr);
		i++;
	}
	if (str[i])
	{
		ft_free_list(nbr);
		ft_error_message("Error");
	}
	return (res * sign);
}


static	void	ft_free_leak(char **str)
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
	t_list	*new_node;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (ft_strlen(av[i]) == 0 || check_digit(av[i]) == 0)
		{
			ft_free_list(nbr);
			ft_error_message("Error");
		}
		str = ft_split(av[i], ' ');
		if (!str)
		{
			ft_free_list(nbr);
			exit(1);
		}
		while (str[j])
		{
			new_node = ft_lstnew(ft_atoi(str[j], nbr));
			if (!new_node)
			{
				ft_free_leak(str);
				ft_free_list(nbr);
				ft_error_message("Error");
			}
			ft_lstadd_back(nbr, new_node);
			ft_duplicate(*nbr);
			free(str[j]);
			j++;
		}
		free(str);
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
