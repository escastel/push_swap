/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:46:53 by escastel          #+#    #+#             */
/*   Updated: 2024/01/12 14:58:15 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sign_and_digit(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-' || str[i][j] == '+')
			{
				j++;
				if (!(str[i][j] >= '0' && str[i][j] <= '9'))
					return (1);
			}
			if (!((str[i][j] >= '0' && str[i][j] <= '9') || str[i][j] == ' '))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check(int argc, char **argv, t_data *data)
{
	data->str = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2)
		data->str = ft_split(argv[1], ' ');
	if (argc > 2)
		data->str = argv + 1;
	if (check_sign_and_digit(data->str))
		return (ft_printf("Error\n"), 1);
	return (0);
}
