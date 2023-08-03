/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:35:40 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/03 13:02:48 by migmoren         ###   ########.fr       */
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

t_stack	*ft_new_node(int elem) //OJO CON ESTAS LLAMADAS QUE PUEDE HABER LEAKS
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->elem = elem;
	stack->next = 0;
	stack->conversion = 0;
	return (stack);
}

int	ft_stacksize(t_stack *stack)
{
	int		i;
	t_stack	*aux;

	i = 0;
	aux = stack;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}

int	ft_index(t_stack *stack, int elem)
{
	int		i;
	t_stack	*aux;

	i = 0;
	aux = stack;
	while (aux)
	{
		i++;
		if (aux->elem == elem)
			return (i);
		aux = aux->next;
	}
	return (-1);
}

int	*ft_cpy_stack(t_stack *stack)
{
	int		*nums;
	int		i;
	t_stack	*aux;

	nums = (int *)malloc(sizeof(int) * ft_stacksize(stack));
	if (!nums)
		return (0);
	i = 0;
	aux = stack;
	while (aux)
	{
		nums[i++] = aux->elem;
		aux = aux->next;
	}
	return (nums);
}
