/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:14:39 by xli               #+#    #+#             */
/*   Updated: 2021/05/23 08:40:25 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ct[0] = ct;
**ct[1] = arr_size;
*/

static void	init(int ct[2], int *arr[2], t_deque *stack[2])
{
	if (ct[1] < 2)
		normal_exit();
	stack[0] = init_deque();
	stack[1] = init_deque();
	if (!stack[0] || !stack[1])
		error_exit();
	init_stack(stack[0], arr[0], ct[1]);
	arr[1] = ft_malloc(ct[1], sizeof(int));
	if (arr[1] == NULL)
		error_exit();
	ct[0] = -1;
	while (++ct[0] < ct[1])
		arr[1][ct[0]] = arr[0][ct[0]];
}

static void	index_nb(t_deque *a, int *arr[2], int arr_size)
{
	int		ct[2];

	ct[0] = -1;
	while (++ct[0] < arr_size)
	{
		ct[1] = -1;
		while (++ct[1] < arr_size)
		{
			if (arr[0][ct[0]] == arr[1][ct[1]])
			{
				arr[0][ct[0]] = ct[1];
				break ;
			}
		}
	}
	a = init_deque();
	ct[0] = -1;
	while (++ct[0] < arr_size)
		deque_push_front(a, arr + ct[0]);
}

int	main(int ac, char **av)
{
	int		*arr[2];
	int		ct[2];
	t_deque	*stack[2];

	ct[1] = get_arr_size(arr, ac, av);
	init(ct, arr, stack);
	ft_sort(arr[1], ct[1]);
	index_nb(stack[0], arr, ct[1]);
	push_swap(stack);
	normal_exit();
}
