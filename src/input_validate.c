/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:41:58 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/01 18:20:47 by jhesso           ###   ########.fr       */
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
*	check if the given string contains only zeros and possibly a sign at the front
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

/* validate_input()
*	check that the input consists of only integers and nothing else
*	No duplicates allowed
*	return: 1 if arguments are valid, 0 if not.
*/
int	input_validate(char **argv, int argc)
{
	int	i;
	int	j;
	int	zero_count;

	i = 1;
	zero_count = 0;
	while (argv[i])
	{
		j = i + 1;
		if (!ft_isnum(argv[i]))
			return (0);
		if (ft_iszero(argv[i]))
			zero_count++;
		if (zero_count > 1)
			return (0);
		if (argc > 2)
			while (argv[j])
			{
				if (!check_duplicates(argv[i], argv[j]))
					return (0);
				j++;
			}
		i++;
	}
	return (1);
}
