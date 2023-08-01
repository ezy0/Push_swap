/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:35:40 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/01 11:35:47 by migmoren         ###   ########.fr       */
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

int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void ft_print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*aux;
	
	i = 0;
	aux = stack_a;
	if (!stack_a)
		ft_printf("stack A vacío\n");
	else
	{
		while (i < ft_stacksize(stack_a))
		{
			ft_printf("%d ", aux->elem);
			aux = aux->next;
			i++;
		}
		ft_printf("\n");
	}
	i = 0;
	aux = stack_b;
	if (!stack_b)
		ft_printf("stack B vacío\n");
	else
	{
		while (i < ft_stacksize(stack_b))
		{
			ft_printf("%d ", aux->elem);
			aux = aux->next;
			i++;
		}
		ft_printf("\n");
	}
}
