/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:54:04 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/01 09:10:21 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack {
	int				elem;
	int				pos;
	struct s_stack	*next;
}						t_stack;

int		main(int argc, char *argv[]);
t_stack	*ft_argv_to_stack(int size, char *argv[]);
void	ft_error(int error);
int		ft_check_arg(t_stack *list, char *arg);
void	ft_free_stack(t_stack *stack);
t_stack	*ft_new_node(int elem);
int		ft_stacksize(t_stack *stack);
//SWAP
void	ft_swap_a(t_stack *stack_a);
void	ft_swap_b(t_stack *stack_b);
void	ft_swap_ab(t_stack *stack_a, t_stack *stack_b);

#endif