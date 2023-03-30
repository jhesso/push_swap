/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:03:54 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/30 04:22:09 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static char	**alloc_operations(char **operations)
{
	char	**temp;
	int		i;

	i = 0;
	while (operations[i])
		i++;
	temp = malloc(sizeof(char *) * (i + 1));
	if (!temp)
		checker_error(operations, NULL, NULL);
	temp[i] = NULL;
	i = 0;
	while (operations[i])
	{
		temp[i] = operations[i];
		i++;
	}
	free (operations);
	operations = malloc(sizeof(char *) * (i + 2));
	if (!operations)
	{
		free_input(temp);
		checker_error(NULL, NULL, NULL);
	}
	operations[i + 1] = NULL;
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

/*	get_operations()
*	read the operations from STDIN
*	returns the operations as a char **
*/
char	**get_operations(void)
{
	char	**operations;
	char	**line;
	int		i;

	i = 0;
	line = malloc(sizeof(char *) * 2);
	if (!line)
		checker_error(NULL, NULL, NULL);
	line[1] = NULL;
	while (get_line(line))
	{
		if (i > 0)
		{
			operations = alloc_operations(operations);
			operations[i] = line[0];
		}
		else
		{
			operations = malloc(sizeof(char *) * 2);
			if (!operations)
				checker_error(NULL, NULL, NULL);
			operations[0] = line[0];
			operations[1] = NULL;
		}
		i++;
	}
	return (operations);
}
