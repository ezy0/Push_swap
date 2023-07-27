/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:54:04 by migmoren          #+#    #+#             */
/*   Updated: 2023/07/27 12:43:58 by migmoren         ###   ########.fr       */
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

#endif