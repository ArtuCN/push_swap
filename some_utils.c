/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:01:04 by aconti            #+#    #+#             */
/*   Updated: 2024/02/28 10:25:08 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(long int *arr, int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		if (arr[i] < arr[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	max(t_stack **stack)
{
	int		max;
	t_stack	*temp;

	temp = *stack;
	max = INT_MIN;
	while (temp)
	{
		if (max < temp->val)
			max = temp->val;
		temp = temp->next;
	}
	return (max);
}

int	type_rot_b(t_stack **stack)
{
	t_stack	*temp;
	int		rot;
	int		rev;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	temp = *stack;
	rot = 0;
	rev = 0;
	while (temp)
	{
		if (temp->val == max(stack))
			break ;
		rot++;
		temp = temp->next;
	}
	rev = counter(*stack) - rot;
	if (rot <= rev)
		return (rot);
	else
		return (rev * -1);
}

void	remove_first(t_stack **stack)
{
	t_stack	*temp;

	temp = (*stack)->next;
	free(*stack);
	(*stack) = temp;
}

void	free_stack(t_stack *head)
{
	t_stack	*current;
	t_stack	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
