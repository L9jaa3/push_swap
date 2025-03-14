/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouarr <ielouarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:35:16 by ielouarr          #+#    #+#             */
/*   Updated: 2025/02/06 16:06:04 by ielouarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
#pragma GCC diagnostic ignored "-Wunused-value"

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	int				indx;
	int				position;
}	t_list;

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
int	ft_error_message(char *message, t_list **nbr);

t_list	*ft_lstnew(int data);
void	ft_lstadd_back(t_list **lst, t_list *nw);
void	ft_duplicate(t_list *lst, char **str);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);
void	ft_parcing(t_list **nbr, char **av);
void	ft_free_leak(char **str);
void	ra(t_list **a, int i);
void	rra(t_list **a, int i);
void	sa(t_list **a);
void	pa(t_list **a, t_list **b);
void	rb(t_list **b, int i);
void	rrb(t_list **b, int i);
void	sb(t_list **b);
void	pb(t_list **a, t_list **b);
t_list	*get_max_number(t_list *lst);
t_list	*get_min_number(t_list *lst);
void	ft_sort_two(t_list **lst);
void	ft_sort_three(t_list **lst);
void	ft_sort_four(t_list **a, t_list **b);
void	ft_sort_five(t_list **a, t_list **b);
void	ft_sort(t_list **a, t_list **b, int i, int j);
int		is_sort(t_list **lst);
void	ft_indexing(t_list *lst);
int		max_position(t_list *lst);
void	mark_position(t_list **stack);
void	ft_sort_b(t_list **a, t_list **b, int i);
void	ft_sort_five_or_less(t_list **a, t_list **b);
int		check_digit(char *s);
#endif