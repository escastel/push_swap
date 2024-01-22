/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:19:05 by escastel          #+#    #+#             */
/*   Updated: 2024/01/12 18:03:58 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	operation_1(t_data *data, int a, int b)
{
	while (a != 0)
	{
		rotate(data, 'a', 1);
		a--;
	}
	while (b != 0)
	{
		reverse_rotate(data, 'b', 1);
		b++;
	}
}

static void	operation_2(t_data *data, int a, int b)
{
	while (b != 0)
	{
		rotate(data, 'b', 1);
		b--;
	}
	while (a != 0)
	{
		reverse_rotate(data, 'a', 1);
		a++;
	}
}

int	actions_pos_and_neg(t_data *data, t_stack *tmp)
{
	int	a;
	int	b;

	a = tmp->cost_a;
	b = tmp->cost_b;
	if (a > b)
	{
		operation_1(data, a, b);
		return (0);
	}
	if (a < b)
	{
		operation_2(data, a, b);
		return (0);
	}
	return (1);
}
