/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:52:58 by angela            #+#    #+#             */
/*   Updated: 2023/09/14 11:44:37 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void push(t_node **origin, t_node **destination, t_pushswap *ps)// a rajouter la char
{
	t_node *temp;
	//on check que la liste est pas vide
	if (list_size(*origin) != 0)
	{
		temp = *origin; // omn stock le node
		*origin = (*origin)->next; // on enleve le 1er...on donne la position first au 2e
		temp->next = *destination; // connect le node au reste de la liste b
		*destination = temp;// enregistre comme debut de liste
		ps->nombre_op++;
		//ft_printf("p\n");

	}
}