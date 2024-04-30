/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:23:59 by aconti            #+#    #+#             */
/*   Updated: 2024/03/23 19:01:22 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ret(long int median, int mayor, int *menor, int size)
{
	if (size % 2 == 0 && (mayor - *menor == -1 || mayor - *menor == 1))
		return (1);
	else if (size % 2 == 1 && !(mayor - *menor))
		return (1);
	else
	{
		*menor = 0;
		return (0);
	}
}

static void	list_set_all(t_stack ***stack, t_stack **tmp,
			long int *median, int *mayor)
{
	*tmp = **stack;
	while (*tmp != NULL && *median != (*tmp)->val)
		*tmp = (*tmp)->next;
	if ((*tmp)->next)
		*median = (*tmp)->next->val;
	*tmp = **stack;
	*mayor = 0;
}

long int	median(t_stack **stack)
{
	int			mayor;
	int			menor;
	long int	median;
	t_stack		*tmp;

	tmp = (*stack)->next;
	mayor = 0;
	menor = 0;
	median = (*stack)->val;
	while (tmp != NULL)
	{
		if (tmp->val > median)
			mayor++;
		else if (tmp->val < median)
			menor++;
		tmp = tmp->next;
		if (!tmp)
		{
			if (ret(median, mayor, &menor, counter(*stack)))
				return (median);
			else
				list_set_all(&stack, &tmp, &median, &mayor);
		}
	}
	return (INT_MAX);
}

static int	arr_set_all(long int *array, long int *median, int size, int *mayor)
{
	int	i;

	*mayor = 0;
	i = 0;
	while (*median != array[i])
		i++;
	if (i + 1 < size)
		*median = array[++i];
	return (0);
}

long int	median_array(long int *array, int size)
{
	int			mayor;
	int			menor;
	long int	median;
	int			i;

	median = array[0];
	mayor = 0;
	menor = 0;
	i = 0;
	while (i < size)
	{
		if (array[i] > median)
			mayor++;
		else if (array[i] < median)
			menor++;
		if (++i == size)
		{
			if (ret(median, mayor, &menor, size))
				return (median);
			else
				i = arr_set_all(array, &median, size, &mayor);
		}
	}
}
