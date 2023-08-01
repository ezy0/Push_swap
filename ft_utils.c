/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:35:40 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/01 08:34:33 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	while (aux)
	{
		stack = stack->next;
		free(aux);
		aux = stack;
	}
}

t_stack	*ft_new_node(int elem)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->elem = elem;
	stack->next = 0;
	return (stack);
}
