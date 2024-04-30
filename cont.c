/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cont.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:59:14 by aconti            #+#    #+#             */
/*   Updated: 2024/03/27 12:24:34 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(char **nptr, int n)
{
	int	i;
	int	j;

	i = 1;
	while (i <= n)
	{
		j = 0;
		while (nptr[i][j])
		{
			if ((nptr[i][j] < '0' || nptr[i][j] > '9') && nptr[i][j]
				!= '-' && nptr[i][j] != '+' && nptr[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	little_check(t_stack **a, t_stack **b)
{
	int	i;
	int	rot_b;

	i = 0;
	if (!a || !(*a) || !b || !(*b))
		return ;
	if (!(*a)->next || !(*b)->next)
		return ;
	while (counter(*b) > 1)
	{
		rot_b = type_rot_b(b);
		if (rot_b <= 0)
		{
			while ((*b)->val != max(b))
				do_rotate(a, b, 5);
			pa(a, b);
		}
		else
		{
			while ((*b)->val != max(b))
				do_rotate(a, b, 2);
			pa(a, b);
		}
	}
}

void	cont(t_stack **a, t_stack **b)
{
	if (counter(*a) == 3)
	{
		if ((max(a) == (*a)->next->val && (*a)->val < (*a)->next->next->val)
			|| max(a) == (*a)->val && (*a)->next->val > (*a)->next->next->val)
		{
			sa(a);
			write (1, "sa\n", 3);
		}
		if (max(a) == (*a)->val && (*a)->next->val < (*a)->next->next->val)
			do_rotate(a, b, 1);
		else if ((*a)->next->val > (*a)->val || max(a) == (*a)->next->val)
			do_rrotate(a, b, 4);
		else if (max(a) == (*a)->next->next->val && (*a)->val > (*a)->next->val)
		{
			sa(a);
			write (1, "sa\n", 3);
		}
	}
	else
	{
		little_check(a, b);
		if (b && *b)
			pa(a, b);
		free_stack(*b);
	}
}
