/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c 	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:13:27 by angela            #+#    #+#             */
/*   Updated: 2023/06/25 16:40:16 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    print_nodes(t_pushswap *ps)// print la liste
{
    int i;
    t_node *current_node;

    current_node = ps->head_a;
    i = 0;

    while (current_node!= NULL)//ici changer , avant current_node ->next
    {
        printf("node(%d)->data = %d\n", i, current_node->data);
        //printf ("adresse du node %p\n", current_node->next);
        current_node = current_node->next;
        i++;
    }
}

long	ft_atol(const char *nptr)
{
	long		i;
	long		res;
	char		*str;
	long		signe;

	i = 0;
	str = (char *)nptr;
	res = 0;
	signe = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (('0' <= str[i] && str[i] <= '9') && str[i])
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (signe * res);
}

int p_error()
{
	write(2, "Error\n", 6);
	return (ERROR);
}
