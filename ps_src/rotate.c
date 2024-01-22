/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:13:49 by escastel          #+#    #+#             */
/*   Updated: 2024/01/12 13:22:50 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	operation(t_stack **stack)
{
	t_stack	*tmp;

	if (ft_lstsize(*stack) < 2)
		return (1);
	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, tmp);
	tmp->next = NULL;
	return (0);
}

void	rotate(t_data *data, char c, int flag)
{
	if (c == 'a')
	{
		if (!(operation(&data->stack_a)))
			if (flag)
				ft_printf("ra\n");
	}
	if (c == 'b')
	{
		if (!(operation(&data->stack_b)))
			if (flag)
				ft_printf("rb\n");
	}
	if (c == 'r')
	{
		if (!(operation(&data->stack_a)))
			if (!(operation(&data->stack_b)))
				if (flag)
					ft_printf("rr\n");
	}
}
