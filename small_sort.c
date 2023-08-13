/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:09:59 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/13 20:39:16 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_small_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	aux = (*stack_a)->next;
	if (!aux || ft_ab_sorted(*stack_a, *stack_b))
	{
		while (*stack_b)
			ft_push_a(stack_a, stack_b);
		return ;
	}
	if (aux->next)
		if ((*stack_a)->elem > aux->elem && (*stack_a)->elem > aux->next->elem)
			ft_rotate_a(stack_a);
	while ((*stack_a)->elem > ft_last_elem(*stack_a)->elem)
	{
		ft_rotate_a(stack_a);
		//ft_print_stacks(*stack_a, *stack_b);
	}
	if ((*stack_a)->elem > (*stack_a)->next->elem)
		ft_swap_a(*stack_a);
	if (ft_ab_sorted(*stack_a, *stack_b) || ft_is_sorted(*stack_a, *stack_b))
		return ;
	ft_push_b(stack_a, stack_b);
	while (ft_b_sorted(*stack_b) == 0)
		ft_sort_b(stack_a, stack_b);
}

void	ft_sort_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	aux = (*stack_b)->next;
	if (aux->next)
		if ((*stack_b)->elem < aux->elem && (*stack_b)->elem < aux->next->elem)
			ft_rotate_b(stack_b);
	if ((*stack_b)->elem < (*stack_b)->next->elem 
		&& ((*stack_a)->elem > (*stack_a)->next->elem 
		&& (*stack_a)->elem < ft_last_elem(*stack_a)->elem))
			ft_swap_ab(*stack_a, *stack_b);
	else if ((*stack_b)->elem < (*stack_b)->next->elem)
		ft_swap_b(*stack_b);
	while (aux->next)
		aux = aux->next;
	while ((*stack_b)->elem < aux->elem)
		ft_rotate_b(stack_b);
}

int	ft_ab_sorted(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*aux;

	i = ft_stacksize(stack_a);
	aux = stack_a;
	if (!stack_b || !stack_a)
		return (0);
	while (i > 1)
	{
		if (aux->elem > aux->next->elem)
			return (0);
		aux = aux->next;
		i--;
	}
	i = ft_stacksize(stack_b);
	aux = stack_b;
	while (i > 1)
	{
		if (aux->elem < aux->next->elem)
			return (0);
		aux = aux->next;
		i--;
	}
	return (1);
}

int	ft_b_sorted(t_stack *stack_b)
{
	int		i;
	t_stack	*aux;

	if (!stack_b)
		return (1);
	i = ft_stacksize(stack_b);
	aux = stack_b;
	while (i > 1)
	{
		if (aux->elem < aux->next->elem)
			return (0);
		aux = aux->next;
		i--;
	}
	return (1);
}

t_stack	*ft_last_elem(t_stack *stack)
{
	t_stack	*aux;
	
	aux = stack;
	while (aux->next)
		aux = aux->next;
	return (aux);
}
