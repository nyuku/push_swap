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
	
	print_nodes(&ps);
    printf("\n------------------\n");

//	swap(&(ps.head));
	rotate_up(&(ps.head_a));
//    reverse_rotate(&(ps.head));

    print_nodes(&ps);

	free_nodes(&ps);
	free_structure(&ps);
	printf("🍕 Ciao Ciao Ciao Ciao Ciao Ciao Ciao Ciao 🍕 \n");
	return (0);
	
}
