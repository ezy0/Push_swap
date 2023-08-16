/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:25:51 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/16 12:30:30 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*aux;

	i = ft_stacksize(stack_a);
	aux = stack_a;
	if (stack_b || !stack_a)
		return (0);
	while (i > 1)
	{
		if (aux->elem > aux->next->elem)
			return (0);
		aux = aux->next;
		i--;
	}
	return (1);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	*nums;
	int	digit;

	nums = ft_cpy_stack(*stack_a);
	nums = ft_radix_positive(nums, ft_stacksize(*stack_a));
	if (!nums)
	{
		ft_free_stack(*stack_a);
		ft_free_stack(*stack_b);
		exit (1);
	}
	ft_stack_conversion(*stack_a, nums);
	free(nums);
	digit = 0;
	while (!ft_is_sorted(*stack_a, *stack_b))
		ft_algorithm(stack_a, stack_b, ft_stacksize(*stack_a), digit++);
}

void	ft_algorithm(t_stack **stack_a, t_stack **stack_b, int size, int digit)
{
	int		i;
	int		bin;

	i = -1;
	while (++i < size)
	{	
		bin = (*stack_a)->conversion >> digit;
		if (bin & 1)
			ft_rotate_a(stack_a);
		else
			ft_push_b(stack_a, stack_b);
	}
	while (*stack_b)
		ft_push_a(stack_a, stack_b);
}
