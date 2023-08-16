/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:54:06 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/16 11:39:34 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_cpy_int(int *nums, int size)
{
	int	*cpy;
	int	i;

	i = 0;
	cpy = (int *)malloc(sizeof(int) * size);
	if (!cpy)
		return (0);
	while (i < size)
	{
		cpy[i] = nums[i];
		i++;
	}
	return (cpy);
}

int	*ft_radix_positive(int *nums, int size)
{
	int	*cpy;
	int	*new;

	if (!nums)
		return (0);
	cpy = ft_cpy_int(nums, size);
	if (!cpy)
	{
		free(nums);
		return (0);
	}
	ft_sort_int(cpy, size);
	new = ft_conversion(nums, cpy, size);
	return (new);
}

void	ft_sort_int(int	*cpy, int size)
{
	int	i;
	int	j;
	int	aux;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (cpy[i] < cpy[j])
			{
				aux = cpy[j];
				cpy[j] = cpy[i];
				cpy[i] = aux;
			}
		}
	}
}

int	*ft_conversion(int *nums, int *cpy, int size)
{
	int	i;
	int	j;
	int	*aux;

	i = -1;
	aux = (int *)malloc(sizeof(int) * size);
	if (!aux)
	{
		free(nums);
		free(cpy);
		return (0);
	}
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (nums[i] == cpy[j])
				aux[i] = j;
	}
	free(nums);
	free(cpy);
	return (aux);
}

void	ft_stack_conversion(t_stack	*stack, int *nums)
{
	t_stack	*aux;
	int		i;

	aux = stack;
	i = 0;
	while (aux)
	{
		aux->conversion = nums[i];
		aux = aux->next;
		i++;
	}
}
