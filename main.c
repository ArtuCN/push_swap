/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:11:23 by aconti            #+#    #+#             */
/*   Updated: 2024/03/27 13:01:21 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sign(char av)
{
	if (av == '+')
		return (1);
	else if (av == '-')
		return (-1);
	else
		return (0);
}

long int	extract_number(char *str, int *index)
{
	long int	num;

	num = 0;
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		num = num * 10 + (str[*index] - '0');
		(*index)++;
	}
	return (num);
}

int	process_string(char *str, long int *nums, int n2)
{
	int			j;
	int			n;
	int			sign;
	long int	num;

	j = 0;
	n = 0;
	num = 0;
	while (str[j])
	{
		sign = 1;
		if ((str[j] < '0' || str[j] > '9') && str[j]
			!= '-' && str[j] != '+' && str[j] != ' ')
			return (INT_MIN);
		if (is_sign(str[j]) == 1 || is_sign(str[j]) == -1)
			sign = is_sign(str[j++]);
		num = extract_number(str, &j);
		if (n + 1 > n2)
			break ;
		nums[n++] = sign * num;
		while (str[j] == ' ')
			j++;
	}
	return (n);
}

int	ft_atoi(char **nptr, long int *nums, int n2)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	while (nptr[i])
	{
		n += process_string(nptr[i], nums + n, n2);
		if (n <= 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			n;
	long int	*nums;

	if (argc < 2 || argv[1][0] == '\0')
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	n = count_num(argv);
	if (n < 0)
		return (write(STDERR_FILENO, "Error\n", 6));
	nums = malloc(sizeof(long int ) * n);
	check_atoi(argv, nums, n);
	if (n == 1 || is_sorted(nums, n))
	{
		free(nums);
		return (0);
	}
	array_to_stack(nums, n, &stack_a);
	sort(&stack_a, &stack_b, n);
	free_stack(stack_a);
	free(nums);
	return (0);
}
