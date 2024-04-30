/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:28:23 by aconti            #+#    #+#             */
/*   Updated: 2024/03/27 12:32:21 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	long			val;
	int				push;
	struct s_stack	*next;
}	t_stack;

//void	print_stack(t_stack *stack);
//main
int			is_sign(char av);
long int	extract_number(char *str, int *index);
int			process_string(char *str, long int *nums, int n2);
int			ft_atoi(char **nptr, long int *nums, int n2);
//check
int			is_sorted_list(t_stack *list);
int			count_num(char **nptr);
int			ft_check(long int *nums, int i);
float		media_array(long array[], int lunghezza);
int			max_node(long int *arr, int size);
//cont
void		cont(t_stack **a, t_stack **b);
void		little_check(t_stack **a, t_stack **b);
int			check_input(char **nptr, int n);
//init
void		f(t_stack *stack);
void		array_to_stack(long int *arr, int size, t_stack **stack);
void		add_push(t_stack *new_node, int size,
				long int *arr, long int media);
//push
void		pa(t_stack **add, t_stack **take);
void		pb(t_stack **add, t_stack **take);
int			penality_rr_push(t_stack *a, int t);
int			penality_r_push(t_stack *a, int t);
int			find_direction_push(t_stack *a, int push);
//rotate
void		rotate(t_stack **lst);
void		reverse_rotate(t_stack **lst);
void		do_rrotate(t_stack **a, t_stack **b, int cod);
void		do_rotate(t_stack **a, t_stack **b, int cod);
int			find_direction_med(t_stack *a, int med);
//sort
int			counter(t_stack *a);
int			check_push(t_stack **a, int i);
void		pre_order(t_stack **a, t_stack **b);
int			penality_rr(t_stack *a, int t);
int			penality_r(t_stack *a, int t);
//void	little_order_min(t_stack **a);
void		sort(t_stack **a, t_stack **b, int n);
//swap
void		sa(t_stack **a);
void		sb(t_stack **a);
void		ss(t_stack **a, t_stack **b);
//void	check_ss(t_stack **a, t_stack **b);
//some utils
int			is_sorted(long int *arr, int n);
int			max(t_stack **stack);
int			type_rot_b(t_stack **stack);
void		free_stack(t_stack *head);
void		remove_first(t_stack **stack);
//norm utils
void		check_atoi(char **argv, long int *nums, int n);
long int	median(t_stack **stack);
long int	median_array(long int *array, int size);
int			err(char **nptr);

#endif
