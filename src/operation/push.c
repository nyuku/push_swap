/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 00:52:58 by angela            #+#    #+#             */
/*   Updated: 2023/09/03 17:43:24 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_node **origin, t_node **destination, t_pushswap *ps, char dest_c)
{
	t_node	*temp;
	temp = *origin;
	*origin = (*origin)->next;
	if (list_size(ps->head_b) == 1 && dest_c == 'b' && ps->head_b->index == 0)
		temp->next = NULL;

	else if (list_size(*origin) != 0)
		temp->next = *destination;
	*destination = temp;
	ps->nombre_op++;
	ft_printf("p%c\n", dest_c);
}
