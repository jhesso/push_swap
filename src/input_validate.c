/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:41:58 by jhesso            #+#    #+#             */
/*   Updated: 2023/01/31 19:34:49 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

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

/* validate_input()
*	check that the input consists of only integers and nothing else
*	No duplicates allowed
*	return: 1 if arguments are valid, 0 if not.
*/
// ? should 02 03 04 etc. be counted as 2 3 4... ?
int	validate_input(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		if (!ft_isnum(argv[i]))
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
