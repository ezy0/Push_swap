/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:04:35 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/13 18:32:28 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int error)
{
	ft_putstr_fd("Error\n", 2);
	if (error == 2)
		ft_putstr_fd("Fallo asignando memoria\n", 2);
	if (error == 3)
		ft_putstr_fd("Datos incorrectos. Solo enteros y sin duplicados\n", 2);
	exit(1);
}
