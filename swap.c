/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 08:59:16 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/01 11:37:20 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stack *stack_a)
{
	int	aux;

	if (ft_stacksize(stack_a) <= 1)
		return ;
	aux = stack_a->elem;
	stack_a->elem = stack_a->next->elem;
	stack_a->next->elem = aux;
	ft_printf("sa\n");
}

void	ft_swap_b(t_stack *stack_b)
{
	int	aux;

	if (ft_stacksize(stack_b) <= 1)
		return ;
	aux = stack_b->elem;
	stack_b->elem = stack_b->next->elem;
	stack_b->next->elem = aux;
	ft_printf("sb\n");
}

void	ft_swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	int	aux;

	if (ft_stacksize(stack_a) <= 1 || ft_stacksize(stack_b) <= 1)
		return ;
	aux = stack_a->elem;
	stack_a->elem = stack_a->next->elem;
	stack_a->next->elem = aux;
	aux = stack_b->elem;
	stack_b->elem = stack_b->next->elem;
	stack_b->next->elem = aux;
	ft_printf("ss\n");
}
