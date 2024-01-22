/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:35:10 by escastel          #+#    #+#             */
/*   Updated: 2024/01/12 17:13:20 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_b(t_stack **stack)
{
	t_stack	*tmp;
	int		size;
	int		up;

	tmp = (*stack);
	size = ft_lstsize(*stack);
	if (size % 2 == 1)
		up = (size / 2) + 1;
	if (size % 2 == 0)
		up = (size / 2);
	while (tmp && up--)
	{
		tmp->cost_b = (tmp->pos) - 1;
		tmp = tmp->next;
	}
	while (tmp)
	{
		tmp->cost_b = (size - tmp->pos + 1) * (-1);
		tmp = tmp->next;
	}
}

void	cost_a(t_data *data)
{
	t_stack	*tmp;
	int		size;
	int		up;

	tmp = data->stack_b;
	size = ft_lstsize(data->stack_a);
	if (size % 2 == 1)
		up = (size / 2) + 1;
	if (size % 2 == 0)
		up = (size / 2);
	while (tmp)
	{
		if (tmp->target_pos <= up)
			tmp->cost_a = (tmp->target_pos) - 1;
		else
			tmp->cost_a = (size - tmp->target_pos + 1) * (-1);
		tmp = tmp->next;
	}
}

int	total_cost(t_stack	*stack)
{
	int	cost;

	if (stack->cost_a > 0 && stack->cost_b > 0)
	{
		if (stack->cost_a > stack->cost_b)
			cost = ft_abs(stack->cost_a);
		else
			cost = ft_abs(stack->cost_b);
	}
	else if (stack->cost_a < 0 && stack->cost_b < 0)
	{
		if (stack->cost_a > stack->cost_b)
			cost = ft_abs(stack->cost_b);
		else
			cost = ft_abs(stack->cost_a);
	}
	else
	{
		if (stack->cost_a > stack->cost_b)
			cost = ft_abs(stack->cost_a) + ft_abs(stack->cost_b);
		else
			cost = ft_abs(stack->cost_a) + ft_abs(stack->cost_b);
	}
	return (cost);
}
