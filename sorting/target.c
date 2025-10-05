/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:17:46 by h-el-ahr          #+#    #+#             */
/*   Updated: 2025/03/05 16:17:47 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*target;
	int		max;

	b = *stack_b;
	while (b)
	{
		a = *stack_a;
		max = INT_MAX;
		target = NULL;
		while (a)
		{
			if (b->data < a->data && a->data < max)
			{
				max = a->data;
				target = a;
			}
			a = a->next;
		}
		if (target == NULL)
			target = find_min(*stack_a);
		b->target = target;
		b = b->next;
	}
}
