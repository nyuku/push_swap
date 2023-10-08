/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:19:08 by angela            #+#    #+#             */
/*   Updated: 2023/10/08 12:59:07 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include<stdio.h>

void deal_with_args(t_pushswap *ps, char **av)
{
	if (ps->mono_arg != 0)
	{
		init_list(ps);
		if (fill_list_mono(ps) == ERROR) // new
		{
			p_error();
			free_nodes(&(ps->head_a));
			free_structure(ps);
			exit(0);
		}
	}
	else
	{
		ps->number_numbers = ps->multi_arg;
		init_list(ps);
		if (fill_list_multi(ps, av) == ERROR) // new
		{
			p_error();
			free_nodes(&(ps->head_a));
			free_structure(ps);
			exit(0);
		}
	}
}


int	main(int ac, char **av)
{
	t_pushswap ps;

	if(ac <= 1)
		return (0);
	ps.nombre_op = 0;
	ps.multi_arg = 0;
	ps.mono_arg = 0;
	check_all_arg(av, ac, &ps);
	deal_with_args(&ps, av);
	if (check_double(ps.head_a) == ERROR)
	{
		p_error();
		free_nodes(&(ps.head_a));
		free_structure(&ps);
		return(0);
	}
	index_node(&ps);
	if (is_already__sorted(&(ps.head_a)) != 0 )
	{
		free_nodes(&(ps.head_a));
		free_structure(&ps);
		return(0);
	}
	ps.head_b = node_init();

	if (ps.number_numbers > 5)
		big_sort(&ps);
	else
		small_sorting(&ps);
	free_nodes(&(ps.head_a));
	free_nodes(&(ps.head_b));
	free_structure(&ps);
	return (0);
}
