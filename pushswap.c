/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:06:38 by jhesso            #+#    #+#             */
/*   Updated: 2023/01/19 19:53:58 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_result(t_list *result)
{
	ft_printf("%s\n", result->content);
}

int	main(void)
{
	t_list	*result = NULL;
	char	*str = "test";

	result->content = str;
	result->next = NULL;
	print_result(result);
	return (0);
}

