/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:49:35 by aconti            #+#    #+#             */
/*   Updated: 2024/03/27 13:06:16 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_atoi(char **argv, long int *nums, int n)
{
	if (!ft_atoi(argv, nums, n) || ft_check(nums, n) == 0)
	{
		free(nums);
		write(STDERR_FILENO, "Error\n", 6);
		exit (0);
	}
}

int	err(char **nptr)
{
	int	i;
	int	j;

	i = 0;
	while (nptr[++i])
	{
		j = 0;
		while (nptr[i][j])
		{
			if (is_sign(nptr[i][j]) && (nptr[i][j + 1] < '0'
				|| nptr[i][j + 1] > '9'))
				return (0);
			if (nptr[i][j] >= '0' && nptr[i][j] <= '9')
			{
				while (nptr[i][j] >= '0' && nptr[i][j] <= '9')
				{
					if (nptr[i][j + 1] == '+' || nptr[i][++j] == '-')
						return (0);
				}
			}
			else
				j++;
		}
	}
	return (1);
}
