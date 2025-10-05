/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:17:33 by h-el-ahr          #+#    #+#             */
/*   Updated: 2025/03/09 21:12:24 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*cheapest(t_stack *b)
{
	t_stack	*cheapest;

	cheapest = b;
	while (b)
	{
		if (b->cost < cheapest->cost)
			cheapest = b;
		b = b->next;
	}
	return (cheapest);
}

static void	move_to_top(t_stack **a, t_stack **b, t_stack *cheapest)
{
	is_bellowmed(*b, cheapest);
	if (cheapest->bellowmed == 0 && cheapest->target->bellowmed == 0)
		while (cheapest != *b && cheapest->target != *a)
			rr(a, b);
	if (cheapest->bellowmed == 1 && cheapest->target->bellowmed == 1)
		while (cheapest != *b && cheapest->target != *a)
			rrr(a, b);
	while ((*b) != cheapest)
	{
		if (cheapest->bellowmed == 0)
			rb(b);
		else
			rrb(b);
	}
	while ((*a) != cheapest->target)
	{
		if (cheapest->target->bellowmed == 0)
			ra(a);
		else
			rra(a);
	}
}

void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	while (*b)
	{
		target(a, b);
		cost(*a);
		cost(*b);
		sum_costs(*b);
		cheap = cheapest(*b);
		move_to_top(a, b, cheap);
		pa(a, b);
	}
}
