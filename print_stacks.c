/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:07:10 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/03 13:09:53 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*aux;

	i = 0;
	aux = stack_a;
	ft_printf("STACK A\n");
	if (!stack_a)
		ft_printf("stack A vacío\n");
	else
	{
		while (i < ft_stacksize(stack_a))
		{
			ft_printf("%d , %d", aux->elem, aux->conversion);
			ft_printf("\n");
			aux = aux->next;
			i++;
		}
	}
	i = 0;
	aux = stack_b;
	ft_printf("STACK B\n");
	if (!stack_b)
		ft_printf("stack B vacío\n");
	else
	{
		while (i < ft_stacksize(stack_b))
		{
			ft_printf("%d , %d", aux->elem, aux->conversion);
			ft_printf("\n");
			aux = aux->next;
			i++;
		}
	}
}
