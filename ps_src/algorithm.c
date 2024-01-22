/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:56:54 by escastel          #+#    #+#             */
/*   Updated: 2024/01/12 17:13:43 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	position(t_data *data)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		pos;

	pos = 1;
	stack_a = data->stack_a;
	while (stack_a)
	{
		stack_a->pos = pos;
		stack_a = stack_a->next;
		pos++;
	}
	pos = 1;
	stack_b = data->stack_b;
	while (stack_b)
	{
		stack_b->pos = pos;
		stack_b = stack_b->next;
		pos++;
	}
}

static	void	target_position2(t_data *data, t_stack *stack_b)
{
	t_stack	*stack_a;
	t_stack	*tmp;

	tmp = NULL;
	stack_a = data->stack_a;
	while (stack_a)
	{
		if (!tmp)
		{
			tmp = stack_a;
			stack_b->target_pos = tmp->pos;
		}
		if (tmp->index > stack_a->index)
		{
			tmp = stack_a;
			stack_b->target_pos = tmp->pos;
		}
		stack_a = stack_a->next;
	}
}

static void	target_position(t_data *data)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*tmp;

	stack_b = data->stack_b;
	while (stack_b)
	{
		tmp = NULL;
		stack_a = data->stack_a;
		while (stack_a)
		{
			if (stack_b->index < stack_a->index)
			{
				if (!tmp)
					tmp = stack_a;
				if (tmp->index > stack_a->index)
					tmp = stack_a;
				stack_b->target_pos = tmp->pos;
			}
			stack_a = stack_a->next;
		}
		if (!tmp)
			target_position2(data, stack_b);
		stack_b = stack_b->next;
	}
}

void	algorithm(t_data *data)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = &data->stack_a;
	while ((*stack_a)->next->next->next)
		push(data, 'b', 1);
	algorithm_three(&data->stack_a, data);
	stack_b = &data->stack_b;
	while ((*stack_b))
	{
		position(data);
		target_position(data);
		cost_b(stack_b);
		cost_a(data);
		actions(data);
		push(data, 'a', 1);
	}
	order_a(data);
}
