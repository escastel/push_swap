/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:13:37 by escastel          #+#    #+#             */
/*   Updated: 2024/01/12 13:23:37 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	operation(t_stack **stack_src, t_stack **stack_dst)
{
	t_stack	*tmp;

	if (!ft_lstsize(*stack_src))
		return (1);
	tmp = *stack_src;
	*stack_src = (*stack_src)->next;
	ft_lstadd_front(stack_dst, tmp);
	return (0);
}

void	push(t_data *data, char c, int flag)
{
	if (c == 'a')
	{
		if (!(operation(&data->stack_b, &data->stack_a)))
			if (flag)
				ft_printf("pa\n");
	}
	if (c == 'b')
	{
		if (!(operation(&data->stack_a, &data->stack_b)))
			if (flag)
				ft_printf("pb\n");
	}
}
