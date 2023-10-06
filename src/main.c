/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:19:08 by angela            #+#    #+#             */
/*   Updated: 2023/10/06 16:04:58 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include<stdio.h>

void deal_with_args(t_pushswap *ps, int ac, char **av)// appel le bon fill list selon le type d'argument
{
	if (ps->mono_arg != 0 && ac == 2)// c'est un seul argument "plop plop plop"
	{
		ps->number_numbers = ps->mono_arg; // transfert info vers une autre variable
		init_list(ps);
		fill_list_mono(ps);

	}
	else if (ac > 2)
	{
		ps->number_numbers = ps->multi_arg;
		init_list(ps);
		fill_list_multi(ps, av);
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
//	init_list(&ps);
	check_all_arg(av, ac, &ps);//check simono arg et multi et elligible

	deal_with_args(&ps, ac, av);// rempli la liste
	//fill_list(&ps, av);
//	print_nodes(&(ps.head_a), 'A');
//	if ((check_double(ps.head_a)) == 0) // DOUBLE
//	{
//		ft_printf("plop\n");
//		free_nodes(&(ps.head_a));// diiiiiifff
//		//free_nodes(&(ps.head_b));
//		free_structure(&ps);
//		return (0);
//	}
	///////////// trie
	ps.head_b = node_init();
	index_node(&ps);


	if (ps.number_numbers > 5)
		big_sort(&ps);
	else
		small_sorting(&ps);
	free_nodes(&(ps.head_a));
	free_nodes(&(ps.head_b));// 2x a ici
	free_structure(&ps);

	return (0);
	
}
