/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:12:34 by escastel          #+#    #+#             */
/*   Updated: 2024/01/22 15:21:31 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps_src/push_swap.h"

/* void	ft_leak(void)
{
	system("leaks -q checker");
} */

static int	operation(char *line, t_data *data)
{
	if (!ft_strncmp(line, "sa\n", 3))
		return (swap(data, 'a', 0), 0);
	if (!ft_strncmp(line, "sb\n", 3))
		return (swap(data, 'b', 0), 0);
	if (!ft_strncmp(line, "ss\n", 3))
		return (swap(data, 's', 0), 0);
	if (!ft_strncmp(line, "pa\n", 3))
		return (push(data, 'a', 0), 0);
	if (!ft_strncmp(line, "pb\n", 3))
		return (push(data, 'b', 0), 0);
	if (!ft_strncmp(line, "ra\n", 3))
		return (rotate(data, 'a', 0), 0);
	if (!ft_strncmp(line, "rb\n", 3))
		return (rotate(data, 'b', 0), 0);
	if (!ft_strncmp(line, "rr\n", 3))
		return (rotate(data, 'r', 0), 0);
	if (!ft_strncmp(line, "rra\n", 4))
		return (reverse_rotate(data, 'a', 0), 0);
	if (!ft_strncmp(line, "rrb\n", 4))
		return (reverse_rotate(data, 'b', 0), 0);
	if (!ft_strncmp(line, "rrr\n", 4))
		return (reverse_rotate(data, 'r', 0), 0);
	return (1);
}

static int	checker(t_data *data)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (operation(line, data))
			return (free (line), ft_printf("Error\n"), 1);
		free (line);
		line = get_next_line(0);
	}
	if (check_order(data) && data->stack_b == NULL)
		return (ft_printf("OK\n"), 0);
	return (ft_printf("KO\n"), 1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (check(argc, argv, data))
		exit(EXIT_FAILURE);
	data->stack_b = NULL;
	if (initialize(data))
		exit(EXIT_FAILURE);
	assign_index(data);
	if (checker(data))
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
