/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:55:01 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/01 08:40:12 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = ft_argv_to_stack(argc, argv);
	stack_b = ft_new_node(0);
	if (!stack_b)
	{
		ft_free_stack(stack_a);
		ft_error(2);
	}
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}

t_stack	*ft_argv_to_stack(int size, char *argv[])
{
	int		i;
	t_stack	*stack;
	t_stack	*aux;

	i = 0;
	stack = 0;
	aux = 0;
	while (++i < size)
	{
		if (ft_check_arg(stack, argv[i]))
		{
			ft_free_stack(stack);
			ft_error(3);
		}
		if (!stack)
			stack = ft_new_node(ft_atoi(argv[i]));
		if (aux)
		{
			aux->next = ft_new_node(ft_atoi(argv[i]));
			aux = aux->next;
		}
		if (i == 1)
			aux = stack;
	}
	return (stack);
}

int	ft_check_arg(t_stack *stack, char *arg)
{
	int		i;
	t_stack	*aux;

	i = -1;
	while (++i < ft_strlen(arg))
		if (arg[i] < 48 || arg[i] > 57)
			return (1);
	if (!stack)
		return (0);
	aux = stack;
	while (aux)
	{
		if (aux->elem == ft_atoi(arg))
			return (1);
		aux = aux->next;
	}
	return (0);
}
