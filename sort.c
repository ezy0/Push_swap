/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:25:51 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/02 20:51:18 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*aux;
	
	i = ft_stacksize - 1;
	aux = stack_a;
	if (stack_b || !stack_a)
		return (0);
	while (i > 1) //Ojo a esta cuenta, que a lo mejor es i > 0
	{
		if (aux->elem > aux->next->elem)
			return (0);
		i--;
	}
	return (1);
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b) //Adaptar si eso para stacks <= 5
{
	int	*nums;

	nums = ft_cpy_stack(stack_a);
	if (!nums)
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		exit (1);
	}
	//pasar a 0 1 2 3...
}
