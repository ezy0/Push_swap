/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:04:35 by migmoren          #+#    #+#             */
/*   Updated: 2023/07/27 12:43:25 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int error)
{
	ft_printf("Error\n");
	if (error == 2)
		ft_printf("Fallo asignando memoria\n");
	if (error == 3)
		ft_printf("Datos incorrectos. Solo enteros y sin duplicados\n");
	exit(1);
}
