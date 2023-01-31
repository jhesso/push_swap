/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:55:47 by jhesso            #+#    #+#             */
/*   Updated: 2023/01/27 12:18:23 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../include/pushswap.h"

int	main(int argc, char **argv)
{
	int	ret;

	if (argc < 2)
	{
		ft_putstr_fd("no arguments given\n", 2);
		return (0);
	}
		ret = validate_input(argv);
		if (ret == 0)
			ft_printf("input was not valid\n");
		else if (ret == 1)
			ft_printf("input was valid\n");
	return (0);
}
