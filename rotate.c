/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:19:12 by aconti            #+#    #+#             */
/*   Updated: 2024/02/28 10:25:01 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **lst)
{
	t_stack	*first;
	t_stack	*temp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	*lst = first->next;
	first->next = NULL;
	temp = *lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = first;
}

void	reverse_rotate(t_stack **lst)
{
	t_stack	*second_last;
	t_stack	*last;

	second_last = NULL;
	last = *lst;
	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *lst;
	second_last->next = NULL;
	*lst = last;
}

void	do_rrotate(t_stack **a, t_stack **b, int cod)
{
	if (cod == 4 && a && *a && (*a)->next)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	else if (cod == 5 && b && *b && (*b)->next)
	{
		reverse_rotate(b);
		write(1, "rrb\n", 4);
	}
	else if (cod == 6 && a && *a && (*a)->next && b && *b && (*b)->next)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		write(1, "rrr\n", 4);
	}
}

void	do_rotate(t_stack **a, t_stack **b, int cod)
{
	if (cod == 1 && a && *a && (*a)->next)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	else if (cod == 2 && b && *b && (*b)->next)
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
	else if (cod == 3 && a && *a && (*a)->next && b && *b && (*b)->next)
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
	}
	else
		do_rrotate(a, b, cod);
}

int	find_direction_med(t_stack *a, int med)
{
	int	pi;
	int	pj;

	pi = penality_r(a, med);
	pj = penality_rr(a, med);
	if (pj < pi)
		return (4);
	else
		return (1);
}
