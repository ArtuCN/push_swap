/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:18:57 by aconti            #+#    #+#             */
/*   Updated: 2024/02/28 10:24:50 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **add, t_stack **take)
{
	t_stack	*g;
	t_stack	*temp;

	if (!add || !take)
		return ;
	g = malloc(sizeof(t_stack));
	if (!g)
	{
		while (*add != NULL)
		{
			temp = *add;
			*add = (*add)->next;
			free(temp);
		}
		return ;
	}
	g->val = (*take)->val;
	g->next = *add;
	*add = g;
	remove_first(take);
	write(1, "pa\n", 3);
}

void	pb(t_stack **add, t_stack **take)
{
	t_stack	*g;
	t_stack	*temp;

	if (!add || !take)
		return ;
	g = malloc(sizeof(t_stack));
	if (!g)
	{
		while (*add != NULL)
		{
			temp = *add;
			*add = (*add)->next;
			free(temp);
		}
		return ;
	}
	g->val = (*take)->val;
	g->next = *add;
	*add = g;
	remove_first(take);
	write(1, "pb\n", 3);
}
