/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_validate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:23:01 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/30 03:30:33 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*	operation_cmp()
*	compares given string to the allowed operations
*	returns 1 if it was valid, 0 if not
*/
static int	operation_cmp(char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		return (1);
	else if (!ft_strcmp(line, "sb\n"))
		return (1);
	else if (!ft_strcmp(line, "ss\n"))
		return (1);
	else if (!ft_strcmp(line, "pa\n"))
		return (1);
	else if (!ft_strcmp(line, "pb\n"))
		return (1);
	else if (!ft_strcmp(line, "ra\n"))
		return (1);
	else if (!ft_strcmp(line, "rb\n"))
		return (1);
	else if (!ft_strcmp(line, "rr\n"))
		return (1);
	else if (!ft_strcmp(line, "rra\n"))
		return (1);
	else if (!ft_strcmp(line, "rrb\n"))
		return (1);
	else if (!ft_strcmp(line, "rrr\n"))
		return (1);
	return (0);
}

/*	operations_validate()
*	validates the given operations
*	returns 1 if everything was valid, 0 if not
*/
int	operations_validate(char **operations)
{
	int	i;

	i = 0;
	while (operations[i])
	{
		if (!operation_cmp(operations[i]))
			return (0);
		i++;
	}
	return (1);
}
