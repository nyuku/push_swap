/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:52:58 by angela            #+#    #+#             */
/*   Updated: 2023/08/18 00:52:59 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_node **origin, t_node **destination)
{
	t_node *temp;
	//on check que la liste est pas vide
	if (list_size(*origin) != 0)
	{
		temp = *origin; // omn stock le node
		*origin = (*origin)->next; // on enleve le 1er...on donne la position first au 2e
		temp->next = *destination; // connect le node au reste de la liste b
		*destination = temp;// enregistre comme debut de liste

	}
}