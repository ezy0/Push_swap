/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:16:40 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/16 13:23:06 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(t_stack **stack)
{
	int		i;
	t_stack	*aux;

	if (!*stack || ft_stacksize(*stack) == 1)
		return ;
	aux = *stack;
	i = ft_stacksize(*stack) - 1;
	while (i > 1)
	{
		i--;
		aux = aux->next;
	}
	aux->next->next = *stack;
	*stack = aux->next;
	aux->next = 0;
}

void	ft_reverse_a(t_stack **stack_a)
{
	ft_reverse(stack_a);
	write(1, "rra\n", 4);
}

void	ft_reverse_b(t_stack **stack_b)
{
	ft_reverse(stack_b);
	write(1, "rrb\n", 4);
}

void	ft_reverse_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse(stack_a);
	ft_reverse(stack_b);
	write(1, "rrr\n", 4);
}
