/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:22:19 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/11 15:49:37 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"
#include <string.h> //! remove for final version and use your own strcmp

static t_operations	*node_create(char *line)
{
	t_operations	*node;

	node = malloc(sizeof(t_operations));
	if (!node)
		return (NULL);
	node->operation = line;
	node->next = NULL;
	return (node);
}

static t_operations	*operations_get_tail(t_operations *operations)
{
	while (operations && operations->next != NULL)
		operations = operations->next;
	return (operations);
}

static void	operations_add_back(t_operations *node, t_operations **operations)
{
	t_operations	*tail;

	if (node == NULL)
		return ;
	if (*operations == NULL)
	{
		*operations = node;
		return ;
	}
	tail = operations_get_tail(*operations);
	tail->next = node;
}

static int	validate_operation(char *line)
{
	if (!strcmp("sa\n", line) || !strcmp("sb\n", line) ||\
		!strcmp("ss\n", line) || !strcmp("pa\n", line) ||\
		!strcmp("pb\n", line) || !strcmp("ra\n", line) ||\
		!strcmp("rb\n", line) || !strcmp("rr\n", line) ||\
		!strcmp("rra\n", line) || !strcmp("rrb\n", line) ||\
		!strcmp("rrr\n", line))
		return (0);
	return (1);
}

t_operations	*read_operations(void)
{
	t_operations	*operations;
	char			*line;
	int				flag;

	flag = 0;
	line = get_next_line(0);
	while (line && !flag)
	{
		ft_printf("looping\n");
		flag = validate_operation(line);
		if (flag == 1)
			break;
		operations_add_back(node_create(line), &operations);
		line = get_next_line(0);
	}
	if (flag == 1)
		checker_error_print(NULL, NULL, &operations);
	return (operations);
}
