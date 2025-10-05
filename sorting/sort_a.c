/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:17:42 by h-el-ahr          #+#    #+#             */
/*   Updated: 2025/03/09 21:18:13 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	two_sort(t_stack **a)
{
	if (!a || !(*a) || !(*a)->next)
		return ;
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

static void	three_sort(t_stack **a)
{
	int	i;
	int	j;
	int	k;

	if (!a)
		return ;
	i = (*a)->data;
	j = (*a)->next->data;
	k = (*a)->next->next->data;
	if ((i < j) && (j > k) && (i < k))
	{
		sa(a);
		ra(a);
	}
	else if ((i > j) && (j < k) && (i < k))
		sa(a);
	else if ((i < j) && (j > k) && (i > k))
		rra(a);
	else if ((i > j) && (j < k) && (i > k))
		ra(a);
	else if ((i > j) && (j > k))
	{
		sa(a);
		rra(a);
	}
}

static void	sort(t_stack **a, t_stack **b)
{
	t_stack	*min;

	while (ft_lstsize(*a) > 3)
		push_to_b(a, b);
	three_sort(a);
	while (ft_lstsize(*b) > 0)
		push_to_a(a, b);
	min = find_min(*a);
	is_bellowmed(*a, min);
	if (is_sorted(*a) == 0)
	{
		while (*a != min)
		{
			if (min->bellowmed == 0)
				ra(a);
			else
				rra(a);
		}
	}
}

void	sort_a(t_stack **a, t_stack **b)
{
	int	n;

	n = ft_lstsize(*a);
	if (n == 2)
		two_sort(a);
	else if (n == 3)
		three_sort(a);
	else
		sort(a, b);
}
