/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:19:08 by angela            #+#    #+#             */
/*   Updated: 2023/08/03 15:11:52 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include<stdio.h>

int	main(int ac, char **av)
{
	t_pushswap ps;
	ps.multi_arg = 0;
	ps.mono_arg = 0;
	check_all_arg(av, ac, &ps);//mono arg et multi
    if (ps.mono_arg != 0 && ac == 2)
    {
        ps.number_numbers = ps.mono_arg;
    }
    else if (ac > 2)
    {
        ps.number_numbers = ps.multi_arg;
    }

    init_list(&ps);
	fill_list(&ps);

	fill_test(&(ps.head_b), &ps);
	index_node(&ps);
	print_nodes(&(ps.head_a), 'A');
	printf("\n\n");
	print_nodes(&(ps.head_b), 'B');
    printf("\n-------After-----------\n");
//-------------  Test   ----------------------------
// 	swap(&(ps.head));
//	rotate_up(&(ps.head_a));
//  reverse_rotate(&(ps.head));
//	push(&(ps.head_b),&(ps.head_a));
//	double_rotate(&(ps.head_b),&(ps.head_a));
//	double_swap(&(ps.head_b),&(ps.head_a));
//	double_reverse_rotate(&(ps.head_b),&(ps.head_a));
	threesome(&ps);
    print_nodes(&(ps.head_a),'A' );
	printf("\n\n");
	print_nodes(&(ps.head_b), 'B');

	free_nodes(&(ps.head_a));
	free_nodes(&(ps.head_a));
	free_structure(&ps);
	printf("🍕 Ciao Ciao Ciao Ciao Ciao Ciao Ciao Ciao 🍕 \n");
	return (0);
	
}
