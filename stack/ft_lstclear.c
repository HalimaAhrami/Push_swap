/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:18:00 by h-el-ahr          #+#    #+#             */
/*   Updated: 2025/03/05 16:18:01 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*a;

	if (!lst || !*lst)
		return ;
	a = *lst;
	while (a)
	{
		tmp = (a)->next;
		free(a);
		a = tmp;
	}
	*lst = NULL;
}
