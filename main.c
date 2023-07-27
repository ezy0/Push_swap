/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:55:01 by migmoren          #+#    #+#             */
/*   Updated: 2023/07/27 12:49:23 by migmoren         ###   ########.fr       */
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
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_b)
	{
		//free(stack_a);
		ft_error(2);
	}
	//free(stack_a); Funcion que recorre el stack y libera nodo por nodo
	//free(stack_b);
	return (0);
}

t_stack	*ft_argv_to_stack(int size, char *argv[]) //Adaptarlo para usar la pila en vez de la lista
{
	int	i;
	t_stack	*stack;

	i = 1;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		ft_error(2);
	while (i < size)
	{
		if (ft_check_arg(stack, argv[i]))
		{
			//free(stack);
			ft_error(3);
		}
		stack[i - 1].elem = ft_atoi(argv[i]);
		i++;
	}
	return (stack);
}

int	ft_check_arg(t_stack *stack, char *arg)
{
	int	i;
	t_stack *aux;

	i = -1;
	aux = stack;
	while (++i < ft_strlen(arg))
		if (arg[i] < 48 || arg[i] > 57)
			return (1);
	i = -1;
	while (aux)
	{
		if (aux->elem == ft_atoi(arg))
			return (1);
		aux = aux->next;
	}
	return (0);
}