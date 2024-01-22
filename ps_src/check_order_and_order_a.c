/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order_and_order_a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:58:36 by escastel          #+#    #+#             */
/*   Updated: 2024/01/12 17:10:30 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_data *data)
{
	t_stack	*tmp;
	t_stack	*aux;

	tmp = data->stack_a;
	aux = data->stack_a->next;
	while (aux)
	{
		if (tmp->value > aux->value)
			return (0);
		aux = aux->next;
		tmp = tmp->next;
	}
	return (1);
}

void	order_a(t_data *data)
{
	t_stack	*tmp;
	int		size;

	if (check_order(data))
		return ;
	tmp = data->stack_a;
	size = ft_lstsize(tmp);
	if ((size % 2) == 1)
		size += 1;
	while ((size / 2 >= tmp->index) && tmp->index != 1)
	{
		reverse_rotate(data, 'a', 1);
		tmp = data->stack_a;
	}
	while ((size / 2 < tmp->index) && tmp->index != 1)
	{
		rotate(data, 'a', 1);
		tmp = data->stack_a;
	}
}
