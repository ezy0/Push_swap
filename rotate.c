/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:54:49 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/01 12:02:19 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	int		i;
	t_stack	*aux;

	if (!*stack || ft_stacksize(*stack) == 1)
		return ;
	aux = *stack;
	i = ft_stacksize(*stack) - 1;
	while (i > 0)
	{
		i--;
		aux = aux->next;
	}
	aux->next = *stack;
	*stack = (*stack)->next;
	aux->next->next = 0;
}

void	ft_rotate_a(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	ft_rotate_b(t_stack **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}
