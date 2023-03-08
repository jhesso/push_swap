/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:41:58 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/08 15:29:32 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	check_duplicates()
*	checkf if given strings are equal
*	return: 1 if they are not, 0 if they are
*/
static int	check_duplicates(char *s1, char *s2)
{
	if (*s1 == '+')
		s1++;
	if (*s2 == '+')
		s2++;
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}

/*	ft_iszero()
*	check if the given string contains only zeros
*	and possibly a sign at the front
*	return: 1 if contains only zeros, 0 if not
*/
static int	ft_iszero(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] && s[i] == '0')
		i++;
	if (s[i] != '\0')
		return (0);
	return (1);
}

/* validate()
*	check that the input consists of only integers and nothing else
*	No duplicates allowed
*	return: 1 if arguments are valid, 0 if not.
*/
static int	validate(char **input, int argc)
{
	int		i;
	int		j;
	int		zero_count;

	zero_count = 0;
	i = 0;
	while (input[i])
	{
		j = i + 1;
		if (!ft_isnum(input[i]))
			return (0);
		if (ft_iszero(input[i]))
			zero_count++;
		if (zero_count > 1)
			return (0);
		if (argc > 2)
			while (input[j])
			{
				if (!check_duplicates(input[i], input[j]))
					return (0);
				j++;
			}
		i++;
	}
	return (1);
}

/*	build_input_str()
*	build input string from argv
*/
static char	**build_input_str(char **argv, int argc)
{
	char	**input;
	int		i;
	int		j;
	int		c;

	input = allocate_str(argv, argc);
	i = 1;
	j = 0;
	while (argv[i])
	{
		c = 0;
		while (argv[i][c] != '\0')
		{
			input[j][c] = argv[i][c];
			c++;
		}
		i++;
		j++;
	}
	return (input);
}

/*	input_validate()
*	validates that the given parameters are valid push_swap parameters
*	returns the input string if parameters are valid
*	prints error on stderr and exits if something is wrong
*/
char	**input_validate(char **argv, int argc)
{
	char	**input;
	int		num_count;

	num_count = 0;
	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		if (!input)
			error_print(NULL, NULL);
		while (input[num_count])
			num_count++;
		if (!validate(input, num_count))
			error_print(NULL, NULL);
		return (input);
	}
	else
	{
		input = build_input_str(argv, argc);
		if (!input)
			error_print(NULL, NULL);
		if (!validate(input, argc))
			error_print(NULL, NULL);
		return (input);
	}
}
