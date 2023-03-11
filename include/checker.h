/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:05:45 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/11 15:48:35 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include "push_swap.h"

typedef struct s_operations
{
	char				*operation;
	struct s_operations	*next;
}						t_operations;

t_operations	*read_operations(void);
void	checker_error_print(t_stack **a, t_stack **b, t_operations **operations);

#endif
