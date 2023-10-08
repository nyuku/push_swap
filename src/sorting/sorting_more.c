/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_more.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 00:09:12 by angela            #+#    #+#             */
/*   Updated: 2023/09/03 17:43:51 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
void push_b_chunks(t_pushswap *ps, int chunks, int round)
{
	int i = 1;
	int limit = round * chunks;
	int border = limit / 2;

	while (i <= chunks)
	{
		if (ps->head_a == NULL)
			break;
		if ((ps->head_a->index <= limit) && (ps->head_a->index >= (limit - (chunks - 1))))
		{
			push(&(ps->head_a), &(ps->head_b), ps, 'b');
			if ((list_size(ps->head_b) >= 2) && (ps->head_b->index > border))
			{
				rotate_up(&(ps->head_b), ps, 'b');
			}
			i++;
		}
		else
			rotate_up(&(ps->head_a), ps, 'a');
	}
}

void b_to_a(t_pushswap *ps)
{
	int max_index;
	int upper = 0;
	while (list_size(ps->head_b) != 0)// tant que b n'est pas vide
	{
		max_index = get_max_index(ps->head_b);// on a l'index le plus grand..
		int index_position = find_index(ps->head_b, max_index);// va chercher la position ou se trouve le plus grand

		upper = is_in_upper_half(ps->head_b, index_position);
		while (ps->head_b->index != max_index)
		{
			//variante where i am
			if (upper == 1)
				rotate_up(&(ps->head_b), ps, 'b');
			else if (upper == 0)
				reverse_rotate(&(ps->head_b), ps, 'b');
		}
		upper = 0;
		push(&(ps->head_b), &(ps->head_a), ps, 'a');
	}
}

void big_sort(t_pushswap *ps)
{
	int chunk_done = 1;
	int chunk;

	if (list_size(ps->head_a) <= 100)
		chunk = 20;
	else
		chunk = 70;

	while (list_size(ps->head_a) > 0)
	{
		push_b_chunks(ps, chunk, chunk_done);
		chunk_done++;
	}
	b_to_a(ps);
}


//---------------------------------------------------------------------------------
int get_min_index(t_node *head)
{
	int min_index = head->index;
	t_node *current = head->next;

	while (current != NULL)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
		}
		current = current->next;
	}

	return min_index;
}
int get_max_index(t_node *head)
{
	int max_index = head->index;
	t_node *current = head->next;

	while (current != NULL)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
		}
		current = current->next;
	}

	return max_index;
}