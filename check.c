/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:13:57 by aconti            #+#    #+#             */
/*   Updated: 2024/03/27 12:32:42 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_list(t_stack *list)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp->next != NULL)
	{
		if (!(tmp->next->val > tmp->val))
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	count_num(char **nptr)
{
	int	n;
	int	i;
	int	j;

	n = 0;
	i = 1;
	if (!err(nptr))
		return (-1);
	while (nptr[i])
	{
		j = 0;
		while (nptr[i][j])
		{
			if (nptr[i][j] >= '0' && nptr[i][j] <= '9')
			{
				while (nptr[i][j] >= '0' && nptr[i][j] <= '9')
					j++;
				n++;
			}
			else
				j++;
		}
		i++;
	}
	return (n);
}

int	ft_check(long int *nums, int i)
{
	int	j;

	i--;
	while (i >= 0)
	{
		j = 0;
		if (nums[i] > 2147483647 || nums[i] < -2147483648)
			return (0);
		while (j < i)
		{
			if ((int)nums[i] == (int)nums[j])
				return (0);
			j++;
		}
		i--;
	}
	return (1);
}

float	media_array(long array[], int lunghezza)
{
	float	media;
	int		i;
	int		somma;

	i = 0;
	if (lunghezza == 0)
		return (0);
	somma = 0;
	while (i < lunghezza)
		somma += array[i++];
	media = (float)somma / lunghezza;
	return (media);
}

int	max_node(long int *arr, int size)
{
	int	i;
	int	max;

	i = 0;
	max = arr[0];
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}
