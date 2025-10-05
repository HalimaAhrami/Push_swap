/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:17:28 by h-el-ahr          #+#    #+#             */
/*   Updated: 2025/03/05 16:17:29 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	cost(t_stack *stack)
{
	int		pos;
	int		size_stack;
	t_stack	*lst;

	pos = 0;
	lst = stack;
	size_stack = ft_lstsize(stack);
	while (lst)
	{
		is_bellowmed(stack, lst);
		if (lst->bellowmed == 0)
			lst->cost = pos;
		else
			lst->cost = size_stack - pos;
		lst = lst->next;
		pos++;
	}
}

void	sum_costs(t_stack *b)
{
	while (b)
	{
		if (b->bellowmed == 0 && b->target->bellowmed == 0)
		{
			if (b->cost < b->target->cost)
				b->cost = b->target->cost;
		}
		else if (b->bellowmed == 1 && b->target->bellowmed == 1)
		{
			if (b->cost < b->target->cost)
				b->cost = b->target->cost;
		}
		else
			b->cost += b->target->cost;
		b = b->next;
	}
}
