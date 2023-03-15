/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:40:56 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/15 17:03:40 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	error_print()
*	frees stacks a and b, prints Error\n on stderr and exits with code 1
*/
void	error_print(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || stack_a != NULL)
		stack_free(stack_a);
	if (stack_b == NULL || stack_b != NULL)
		stack_free(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

/*	alocate_str()
*	allocates memory for a 2d array of strings that we use to create the
*	input str that we then validate and pass onto the rest of our program
*/
char	**allocate_str(char**argv, int argc)
{
	char	**input;
	int		i;
	int		j;

	i = 1;
	j = 0;
	input = malloc(sizeof(char *) * argc);
	if (!input)
		error_print(NULL, NULL);
	input[argc -1] = NULL;
	while (i < argc)
	{
		input[j] = ft_calloc(ft_strlen(argv[i]) + 1, sizeof(char));
		if (!input[j])
		{
			if (input)
				free(input);
			error_print(NULL, NULL);
		}
		j++;
		i++;
	}
	return (input);
}

/*	free_input()
*	frees the input string we created
*/
void	free_input(char **input)
{
	int		i;

	if (input == NULL)
		return ;
	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
}
