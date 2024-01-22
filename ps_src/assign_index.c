/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:27:15 by escastel          #+#    #+#             */
/*   Updated: 2024/01/12 12:57:02 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_data *data)
{
	t_stack	*tmp;
	t_stack	*aux;

	tmp = data->stack_a;
	while (tmp)
	{
		aux = data->stack_a;
		while (aux)
		{
			if (tmp->value > aux->value)
				tmp->index += 1;
			aux = aux->next;
		}
		tmp = tmp->next;
	}
}
