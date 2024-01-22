/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:47:24 by escastel          #+#    #+#             */
/*   Updated: 2024/01/22 12:42:52 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	ft_leak(void)
{
	system("leaks -q push_swap");
} */

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (check(argc, argv, data))
		exit(EXIT_FAILURE);
	data->stack_b = NULL;
	if (initialize(data))
		exit(EXIT_FAILURE);
	assign_index(data);
	if (check_order(data))
		exit(EXIT_SUCCESS);
	select_algorithm(data);
	exit(EXIT_SUCCESS);
}
