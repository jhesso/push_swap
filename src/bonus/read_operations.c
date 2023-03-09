/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:22:19 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/09 17:51:22 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

// utilize get next line here
t_operations	*read_operations(void)
{
	t_operations	*operations;
	char			*line;
	int				fd;

	fd = open("/dev/fd/1", O_RDONLY);
	if (fd == -1)
		error_print(NULL, NULL);
	line = get_next_line(fd);
	while (line)
	{
		ft_printf("looping\n");
		operations_add_back(node_create(line), &operations);
		line = get_next_line(fd);
	}
	return (operations);
}
