/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:03:54 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/16 19:05:47 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static char	**alloc_operations(char **operations)
{
	char	**temp;
	int		i;

	i = 0;
	if (!operations)
	{
		operations = malloc(sizeof(char *));
		if (!operations)
			checker_error(NULL, NULL, NULL);
		operations[0]=  NULL;
	}
	while (operations[i] != NULL)
		i++;
	temp = malloc(sizeof(char *) * i + 1);
	if (!temp)
		checker_error(operations, NULL, NULL);
	temp[i - 1] = NULL;
	i = 0;
	while (operations[i])
	{
		temp[i] = operations[i];
		i++;
	}
	free (operations);
	operations = malloc(sizeof(char *) * i + 1);
	if (!operations)
	{
		free_input(temp);
		checker_error(NULL, NULL, NULL);
	}
	operations[i] = NULL;
	i = 0;
	while (temp[i])
	{
		operations[i] = temp[i];
		i++;
	}
	return (operations);
}

static char	**get_line(char **line)
{
	line[0] = get_next_line(STDIN_FILENO);
	return (line);
}

char	**get_operations(void)
{
	char	**operations;
	char	**line;
	int		i;

	i = 0;
	line = malloc(sizeof(char *) * 2);
	if (!line)
		checker_error(NULL, NULL, NULL);
	// get_line(line);
	line[1] = NULL;
	// ft_printf("%s\n", line[0]);
	while (get_line(line))
	{
		operations = alloc_operations(operations);
		operations[i] = line[0];
		debug_input_print(operations);
		i++;
	}
	return (operations);
}
