/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:17:50 by h-el-ahr          #+#    #+#             */
/*   Updated: 2025/03/06 23:11:59 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (stack->data < min->data)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	is_bellowmed(t_stack *stack, t_stack *node)
{
	int	middle;
	int	pos;

	middle = ft_lstsize(stack) / 2;
	pos = 0;
	while (stack)
	{
		if (stack == node)
		{
			if (pos <= middle)
				node->bellowmed = 0;
			if (pos > middle)
				node->bellowmed = 1;
			return ;
		}
		stack = stack->next;
		pos++;
	}
}

int	is_sorted(t_stack *stack)
{
	t_stack	*a;

	a = stack;
	if (!stack || !stack->next)
		return (1);
	while (a && a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}
