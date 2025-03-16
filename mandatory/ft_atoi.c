/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouarr <ielouarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:36:12 by ielouarr          #+#    #+#             */
/*   Updated: 2025/03/16 16:44:43 by ielouarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_overflow(long res, int sign, char **str, t_list *lst)
{
	if ((res * sign > 2147483647) || (res * sign < -2147483648))
	{
		ft_free_leak(str);
		ft_error_message("Error", &lst);
	}
}

static void	check_digit_atoi(char c, char **str, t_list *lst)
{
	if (c < '0' || c > '9')
	{
		ft_free_leak(str);
		ft_error_message("Error", &lst);
	}
}

static void	check_sign(int *sign, const char *str, int *i)
{
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			(*sign) *= -1;
		(*i)++;
	}
}

static int	process_number(const char *str, char **s, t_list *lst)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	check_sign(&sign, str, &i);
	if (str[i] == '\0')
		ft_error_message("Error", &lst);
	while (str[i])
	{
		check_digit_atoi(str[i], s, lst);
		res = res * 10 + (str[i] - '0');
		check_overflow(res, sign, s, lst);
		i++;
	}
	return (res * sign);
}

int	ft_atoi(char **s, const char *str, t_list *lst)
{
	int	result;

	result = process_number(str, s, lst);
	return (result);
}
