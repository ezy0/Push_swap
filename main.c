/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:55:01 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/28 10:49:41 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	sp_size(char *split)
{
	int	i;
	int	size;

	i = -1;
	size = 0;
	while (split && split[++i])
		if (split[i] == ' ' && i < ft_strlen(split) - 1)
			size++;
	return (size + 1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2 || (argv[1] && ft_strlen(argv[1]) < 1))
		return (0);
	if (argc == 2)
		stack_a = ft_split_to_stack(sp_size(argv[1]), ft_split(argv[1], ' '));
	else
		stack_a = ft_argv_to_stack(argc, argv);
	if (!stack_a)
		return (0);
	stack_b = 0;
	if (ft_stacksize(stack_a) <= 5)
		while (ft_is_sorted(stack_a, stack_b) == 0)
			ft_small_sort(&stack_a, &stack_b);
	else
		ft_sort(&stack_a, &stack_b);
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
			ft_error(stack);
		if (!stack)
			stack = ft_new_node((int)ft_atoi(argv[i]));
		if (!stack)
			ft_error(stack);
		if (aux)
		{
			aux->next = ft_new_node((int)ft_atoi(argv[i]));
			aux = aux->next;
		}
		if (i == 1)
			aux = stack;
	}
	return (stack);
}

t_stack	*ft_split_to_stack(int size, char *split[])
{
	int		i;
	t_stack	*stack;
	t_stack	*aux;

	i = -1;
	stack = 0;
	aux = 0;
	while (++i < size)
	{
		if (ft_check_arg(stack, split[i]))
			ft_error(stack);
		if (!stack)
			stack = ft_new_node((int)ft_atoi(split[i]));
		if (!stack)
			ft_error(stack);
		if (aux)
		{
			aux->next = ft_new_node((int)ft_atoi(split[i]));
			aux = aux->next;
		}
		if (i == 0)
			aux = stack;
	}
	return (stack);
}

int	ft_check_arg(t_stack *stack, char *arg)
{
	int		i;
	t_stack	*aux;

	i = -1;
	if (!arg)
		return (1);
	while (++i < ft_strlen(arg))
		if ((i != 0 && (arg[i] == '-' || arg[i] == '+'))
			|| ((arg[i] < 48 || arg[i] > 57) && arg[i] != '-' && arg[i] != '+')
			|| (ft_strlen(arg) == 1 && (arg[i] == '-' || arg[i] == '+')))
			return (1);
	if (ft_atoi(arg) < -2147483648 || ft_atoi(arg) > 2147483647
		|| ft_strlen(arg) > 11)
		return (1);
	if (!stack)
		return (0);
	aux = stack;
	while (aux)
	{
		if (aux->elem == (int)ft_atoi(arg))
			return (1);
		aux = aux->next;
	}
	return (0);
}
