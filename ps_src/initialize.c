/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:21:32 by escastel          #+#    #+#             */
/*   Updated: 2024/01/22 11:04:04 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicates(long int value, t_data *data)
{
	t_stack	*tmp;

	tmp = data->stack_a;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if ((long int)tmp->value == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	initialize(t_data *data)
{
	t_stack		*new_node;
	long int	value;
	int			i;

	i = 0;
	new_node = NULL;
	data->stack_a = NULL;
	while (data->str[i])
	{
		value = ft_atoi(data->str[i]);
		if (value > INT_MAX || value < INT_MIN)
			return (ft_printf("Error\n"), 1);
		if (check_duplicates(value, data))
			return (ft_printf("Error\n"), 1);
		new_node = ft_lstnew(value);
		ft_lstadd_back(&data->stack_a, new_node);
		i++;
	}
	return (0);
}
