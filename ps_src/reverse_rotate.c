/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:14:08 by escastel          #+#    #+#             */
/*   Updated: 2024/01/12 13:23:27 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	operation(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*aux;

	if (ft_lstsize(*stack) < 2)
		return (1);
	tmp = ft_lstlast(*stack);
	aux = *stack;
	while (aux->next->next)
		aux = aux->next;
	aux->next = NULL;
	ft_lstadd_front(stack, tmp);
	return (0);
}

void	reverse_rotate(t_data *data, char c, int flag)
{
	if (c == 'a')
	{
		if (!(operation(&data->stack_a)))
			if (flag)
				ft_printf("rra\n");
	}
	if (c == 'b')
	{
		if (!(operation(&data->stack_b)))
			if (flag)
				ft_printf("rrb\n");
	}
	if (c == 'r')
	{
		if (!(operation(&data->stack_a)))
			if (!(operation(&data->stack_b)))
				if (flag)
					ft_printf("rrr\n");
	}
}
