/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_op_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:39:42 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/30 21:28:12 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	do_rotates(char *op, t_stack **a, t_stack **b)
{
	int	fail;

	fail = 0;
	if (!ft_strcmp(op, "ra\n"))
		fail = op_ra(a);
	else if (!ft_strcmp(op, "rb\n"))
		fail = op_rb(b);
	else if (!ft_strcmp(op, "rr\n"))
		fail = op_rr(a, b);
	else if (!ft_strcmp(op, "rra\n"))
		fail = op_rra(a);
	else if (!ft_strcmp(op, "rrb\n"))
		fail = op_rrb(b);
	else if (!ft_strcmp(op, "rrr\n"))
		fail = op_rrr(a, b);
	if (fail == 0)
		checker_error(a, b);
}

void	do_operation(char *op, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(op, "sa\n"))
		op_sa(a);
	else if (!ft_strcmp(op, "sb\n"))
		op_sb(b);
	else if (!ft_strcmp(op, "ss\n"))
		op_ss(a, b);
	else if (!ft_strcmp(op, "pa\n"))
		op_pa(a, b);
	else if (!ft_strcmp(op, "pb\n"))
		op_pb(b, a);
	else
		do_rotates(op, a, b);
}

void	execute_op(t_stack **a, t_stack **b)
{
	char	*op;

	op = get_next_line(STDIN_FILENO);
	while (op)
	{
		do_operation(op, a, b);
		free(op);
		op = get_next_line(STDIN_FILENO);
	}
}
