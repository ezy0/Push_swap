/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:54:04 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/15 10:26:27 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack {
	int				elem;
	int				pos;
	int				conversion;
	struct s_stack	*next;
}						t_stack;

int		main(int argc, char *argv[]);
t_stack	*ft_argv_to_stack(int size, char *argv[]);
void	ft_error(void);
int		ft_check_arg(t_stack *list, char *arg);
void	ft_free_stack(t_stack *stack);
t_stack	*ft_new_node(int elem);
int		ft_stacksize(t_stack *stack);
int		ft_index(t_stack *stack, int elem);
int		*ft_cpy_stack(t_stack *stack);
//SWAP
void	ft_swap_a(t_stack *stack_a);
void	ft_swap_b(t_stack *stack_b);
void	ft_swap_ab(t_stack *stack_a, t_stack *stack_b);
//PUSH
void	ft_push_a(t_stack **stack_a, t_stack **stack_b);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b);
//ROTATE
void	ft_rotate(t_stack **stack);
void	ft_rotate_a(t_stack **stack_a);
void	ft_rotate_b(t_stack **stack_b);
void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b);
//REVERSE
void	ft_reverse(t_stack **stack);
void	ft_reverse_a(t_stack **stack_a);
void	ft_reverse_b(t_stack **stack_b);
void	ft_reverse_ab(t_stack **stack_a, t_stack **stack_b);
//SORT
int		ft_is_sorted(t_stack *stack_a, t_stack *stack_b);
void	ft_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_algorithm(t_stack **stack_a, t_stack **stack_b, int size, int digit);
//RADIX CONVERSION
int		*ft_cpy_int(int *nums, int size);
int		*ft_radix_positive(int *nums, int size);
void	ft_sort_int(int	*cpy, int size);
int		*ft_conversion(int *nums, int *cpy, int size);
void	ft_stack_conversion(t_stack	*stack, int *nums);
//SMALL SORT
void	ft_small_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_b(t_stack **stack_a, t_stack **stack_b);
int		ft_ab_sorted(t_stack *stack_a, t_stack *stack_b);
int		ft_b_sorted(t_stack *stack_b);
t_stack	*ft_last_elem(t_stack *stack);

void	ft_print_stacks(t_stack *stack_a, t_stack *stack_b);

#endif