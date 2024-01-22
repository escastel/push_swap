/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:04:24 by escastel          #+#    #+#             */
/*   Updated: 2024/01/12 15:14:24 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	second_digit_is_bigger(t_stack **stack, t_data *data)
{
	t_stack	*tmp;

	tmp = (*stack);
	if (tmp->index < tmp->next->next->index)
	{
		reverse_rotate(data, 'a', 1);
		swap(data, 'a', 1);
	}
	else
		reverse_rotate(data, 'a', 1);
}

static void	first_digit_is_bigger(t_stack **stack, t_data *data)
{
	t_stack	*tmp;

	tmp = (*stack);
	if (tmp->next->index > tmp->next->next->index)
	{
		rotate(data, 'a', 1);
		swap(data, 'a', 1);
	}
	else
		rotate(data, 'a', 1);
}

void	algorithm_three(t_stack **stack, t_data *data)
{
	t_stack	*tmp;

	tmp = (*stack);
	if (check_order(data))
		return ;
	if (tmp->index < tmp->next->index)
		second_digit_is_bigger(stack, data);
	if (tmp->index > tmp->next->index)
	{
		if (tmp->index > tmp->next->next->index)
			first_digit_is_bigger(stack, data);
		else
			swap(data, 'a', 1);
	}
}

void	select_algorithm(t_data *data)
{
	int	count;

	count = ft_lstsize(data->stack_a);
	if (count == 2)
		swap(data, 'a', 1);
	if (count == 3)
		algorithm_three(&data->stack_a, data);
	else
		algorithm(data);
}
