/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:47:20 by escastel          #+#    #+#             */
/*   Updated: 2024/01/12 17:57:27 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include "../libft/libft.h"

typedef struct s_data
{
	char	**str;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_data;

int		check(int argc, char **argv, t_data *data);
int		initialize(t_data *data);
void	assign_index(t_data *data);
int		check_order(t_data *data);
void	swap(t_data *data, char c, int flag);
void	push(t_data *data, char c, int flag);
void	rotate(t_data *data, char c, int flag);
void	reverse_rotate(t_data *data, char c, int flag);
void	select_algorithm(t_data *data);
void	algorithm_three(t_stack **stack, t_data *data);
void	algorithm(t_data *data);
void	cost_a(t_data *data);
void	cost_b(t_stack **stack);
int		total_cost(t_stack	*stack);
void	actions(t_data *data);
void	order_a(t_data *data);
int		actions_pos_and_neg(t_data *data, t_stack *tmp);

#endif