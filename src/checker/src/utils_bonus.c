/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:14:58 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/30 04:17:52 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

/*	checker_error()
*	frees operations, stacks a and b, prints Error\n on stderr\
*	and exits with code 1
*/
void	checker_error(char **operations, t_stack **a, t_stack **b)
{
	if (operations)
		free_input(operations);
	if (a)
		stack_free(a);
	if (b)
		stack_free(b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
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
		checker_error(NULL, NULL, NULL);
	input[argc -1] = NULL;
	while (i < argc)
	{
		input[j] = ft_calloc(ft_strlen(argv[i]) + 1, sizeof(char));
		if (!input[j])
		{
			if (input)
				free(input);
			checker_error(NULL, NULL, NULL);
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
