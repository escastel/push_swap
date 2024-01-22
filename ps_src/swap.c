/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:13:28 by escastel          #+#    #+#             */
/*   Updated: 2024/01/12 13:22:30 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	operation(t_stack **stack)
{
	t_stack	*swap;

	if (ft_lstsize(*stack) < 2)
		return (1);
	swap = *stack;
	*stack = (*stack)->next;
	swap->next = (*stack)->next;
	(*stack)->next = swap;
	return (0);
}

void	swap(t_data *data, char c, int flag)
{
	if (c == 'a')
	{
		if (!(operation(&data->stack_a)))
			if (flag)
				ft_printf("sa\n");
	}
	if (c == 'b')
	{
		if (!(operation(&data->stack_b)))
			if (flag)
				ft_printf("sb\n");
	}
	if (c == 's')
	{
		if (!(operation(&data->stack_a)))
			if (!(operation(&data->stack_b)))
				if (flag)
					ft_printf("ss\n");
	}
}
