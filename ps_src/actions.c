/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:44:47 by escastel          #+#    #+#             */
/*   Updated: 2024/01/12 18:02:47 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	actions_positive2(t_data *data, int a, int b)
{
	if (a > 0)
	{
		while (a != 0)
		{
			rotate(data, 'a', 1);
			a--;
		}
	}
	if (b > 0)
	{
		while (b != 0)
		{
			rotate(data, 'b', 1);
			b--;
		}
	}
}

static	int	actions_positive(t_data *data, t_stack *tmp)
{
	int	a;
	int	b;

	a = tmp->cost_a;
	b = tmp->cost_b;
	if (a > 0 && b > 0)
	{
		while (a != 0 && b != 0)
		{
			rotate(data, 'r', 1);
			a--;
			b--;
		}
		actions_positive2(data, a, b);
		return (0);
	}
	return (1);
}

static	void	actions_negative2(t_data *data, int a, int b)
{
	if (a < 0)
	{
		while (a != 0)
		{
			reverse_rotate(data, 'a', 1);
			a++;
		}
	}
	if (b < 0)
	{
		while (b != 0)
		{
			reverse_rotate(data, 'b', 1);
			b++;
		}
	}
}

static	int	actions_negative(t_data *data, t_stack *tmp)
{
	int	a;
	int	b;

	a = tmp->cost_a;
	b = tmp->cost_b;
	if (a < 0 && b < 0)
	{
		while (a != 0 && b != 0)
		{
			reverse_rotate(data, 'r', 1);
			a++;
			b++;
		}
		actions_negative2(data, a, b);
		return (0);
	}
	return (1);
}

void	actions(t_data *data)
{
	t_stack	*stack_b;
	t_stack	*tmp;
	int		cost_tmp;

	tmp = NULL;
	stack_b = data->stack_b;
	while (stack_b)
	{
		if (!tmp)
		{
			cost_tmp = total_cost(stack_b);
			tmp = stack_b;
		}
		if (cost_tmp > total_cost(stack_b))
		{
			cost_tmp = total_cost(stack_b);
			tmp = stack_b;
		}
		stack_b = stack_b->next;
	}
	if (actions_positive(data, tmp))
		if (actions_negative(data, tmp))
			if (actions_pos_and_neg(data, tmp))
				return ;
}
