/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:18:16 by h-el-ahr          #+#    #+#             */
/*   Updated: 2025/03/12 03:23:46 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_check_space(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && str[i][j] == ' ')
			j++;
		if (!str[i][j])
			return (0);
		i++;
	}
	return (1);
}

static int	*ft_nbr(char **str)
{
	int	i;
	int	*nbr;
	int	err;

	i = 0;
	err = 0;
	while (str[i])
	{
		if (!is_nbr(str[i]))
			exit((write(2, "Error\n", 6), ft_free(str), 1));
		i++;
	}
	nbr = malloc(i * sizeof(int));
	if (!nbr)
		return (0);
	i = 0;
	while (str[i])
	{
		nbr[i] = ft_atoi(str[i], &err);
		if (err == 1)
			exit((write(2, "Error\n", 6), free(nbr), ft_free(str), 1));
		i++;
	}
	return (nbr);
}

static void	init_a(t_stack **a, char **av)
{
	char	**str;
	int		*nbr;

	int (i), (n);
	i = 0;
	n = 0;
	if (!ft_check_space(av))
		exit((write(2, "Error\n", 6), 1));
	str = ft_split(av);
	if (!str || !str[0])
		exit((write(2, "Error\n", 6), ft_free(str), 1));
	nbr = ft_nbr(str);
	if (!nbr)
		exit((write(2, "Error\n", 6), free(nbr), ft_free(str), 1));
	while (str[n])
		n++;
	if (is_dup(nbr, n) == 1)
	{
		while (i < n)
			ft_lstadd_back(a, ft_lstnew(nbr[i++]));
	}
	else
		exit((write(2, "Error\n", 6), free(nbr), ft_free(str), 1));
	free(nbr);
	ft_free(str);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac >= 2)
	{
		init_a(&a, av);
		if (!is_sorted(a))
			sort_a(&a, &b);
		ft_lstclear(&a);
	}
	return (0);
}
