/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_more.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 00:09:12 by angela            #+#    #+#             */
/*   Updated: 2023/08/20 15:50:28 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    sorting_20(t_pushswap *ps, int limit)
{
	int tour = 1; // tour tranche
	t_node *temp;



	while (ps->head_a != NULL)
	{
		temp = ps->head_a;
		int r =1;
		while (temp != NULL)
		{

			if ((temp->index <= limit) && (temp->index > (limit / 2))) // on cherche la grosse demi tranche
			{
				if (r < (ps->number_numbers / 2)) // sup petit
				{
					while ((ps->head_a)->index != temp->index)
						rotate_up(&(ps->head_a), ps);
					push(&(ps->head_a), &(ps->head_b), ps);
					//et rotate dans b si au moins 2 element
				}
				else if (r > (ps->number_numbers / 2)) // inf grand
				{
					while ((ps->head_a)->index != temp->index)
						reverse_rotate(&(ps->head_a), ps);
					push(&(ps->head_a), &(ps->head_b), ps);
					//et rotate dans b si au moins 2 element
				}
			}
			temp = temp->next;
			r++;
		}
		if (tour != 1) {
			int i = 0;
			while (i < 10) {
				rotate_up(&(ps->head_b), ps);
				i++;
			}
		}
		//faudrait mettre les 10 prochains gros en bas en rotate si tour != 1
		temp = ps->head_a;
		r =1;
		while (temp != NULL)
		{
			if ((temp->index > (limit - 19)) && (temp->index <= (limit - 10))) // on cherche la petite demi tranche
			{
				if (r < (ps->number_numbers / 2)) // sup petit
				{
					while ((ps->head_a)->index != temp->index)
						rotate_up(&(ps->head_a), ps);
					push(&(ps->head_a), &(ps->head_b), ps);
				}
				else if (r > (ps->number_numbers / 2)) // inf grand
				{
					while ((ps->head_a)->index != temp->index)
						reverse_rotate(&(ps->head_a), ps);
					push(&(ps->head_a), &(ps->head_b), ps);
				}
			}
			temp = temp->next;
			r++;
		}
		tour++;
	}
}


//le soucis c'est que ca marche pour le 1ere tranche mais pas pour les prochaine...
//meilleur tant de rotate les grand quand on met dedans

