/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:18:46 by h-el-ahr          #+#    #+#             */
/*   Updated: 2025/03/12 03:53:02 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				bellowmed;
	int				rank;
	int				cost;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

/*operations***********************************************/
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
/**********************************************************/
void	ra(t_stack **stack);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
/**********************************************************/
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
/**********************************************************/
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
/*input****************************************************/
char	**ft_split(char **s);
char	**ft_free(char **s);
char	*ft_strdup(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strlen(const char *s);
int		ft_atoi(char *str, int *err);
int		is_nbr(char *str);
int		is_dup(int *a, int n);
/*stack****************************************************/
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst);
t_stack	*ft_lstnew(int data);
int		ft_lstsize(t_stack *lst);
/*sorting**************************************************/
void	sort_a(t_stack **a, t_stack **b);
void	push_to_a(t_stack **a, t_stack **b);
t_stack	*find_min(t_stack *stack);
void	is_bellowmed(t_stack *stack, t_stack *node);
int		is_sorted(t_stack *stack);
void	target(t_stack **stack_a, t_stack **stack_b);
void	cost(t_stack *stack);
void	sum_costs(t_stack *b);
void	push_to_b(t_stack **a, t_stack **b);
#endif