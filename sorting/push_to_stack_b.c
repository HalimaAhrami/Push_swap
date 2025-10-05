/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:17:37 by h-el-ahr          #+#    #+#             */
/*   Updated: 2025/03/09 21:10:04 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	get_rank(t_stack **head)
{
	int		rank;
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = *head;
	while (tmp)
	{
		rank = 0;
		tmp1 = *head;
		while (tmp1)
		{
			if (tmp->data > tmp1->data)
				rank++;
			tmp1 = tmp1->next;
		}
		tmp->rank = rank;
		tmp = tmp->next;
	}
}

static void	push_by_rank(t_stack **a, t_stack **b)
{
	get_rank(a);
	while ((*a)->rank > ft_lstsize(*a) / 2)
		ra(a);
	pb(a, b);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	while (ft_lstsize(*a) > 3)
		push_by_rank(a, b);
}
