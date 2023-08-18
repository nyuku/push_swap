/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:24:36 by angela            #+#    #+#             */
/*   Updated: 2023/08/18 16:24:37 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"


//void    small_sorting(t_pushswap *ps)
//{
//	if (ps->number_numbers == 2)
//		duo(ps);
//	if (ps->number_numbers == 3)
//		threesome(ps);
//	if (ps->number_numbers == 4)
//		sorting_for(ps);
//	if (ps->number_numbers == 5)
//		sorting_five(ps);
//
//
//}
//void    duo(t_pushswap *ps)
//{
//
//}


//il y 5 cas à trier

//1-3-2 ->swap,rotate
//2-1-3 ->swap
//3-2-1 ->swap, r.rotate
//3-1-2 ->rotate
//2-3-1 ->r.rotate
void    threesome(t_pushswap *ps)
{
	if (ps->head_a->index == 1 && ps->head_a->next->index == 3 && ps->head_a->next->next->index == 2)
	{
		swap(&(ps->head_a));
		rotate_up(&(ps->head_a));
	}
	else if (ps->head_a->index == 2 && ps->head_a->next->index == 1 && ps->head_a->next->next->index == 3)
	{
		swap(&(ps->head_a));
	}
	else if (ps->head_a->index == 3 && ps->head_a->next->index == 2 && ps->head_a->next->next->index == 1)
	{
		swap(&(ps->head_a));
		reverse_rotate(&(ps->head_a));
	}
	else if (ps->head_a->index == 3 && ps->head_a->next->index == 1 && ps->head_a->next->next->index == 2)
	{
		rotate_up(&(ps->head_a));
	}
	else if (ps->head_a->index == 2 && ps->head_a->next->index == 3 && ps->head_a->next->next->index == 1)
	{
		reverse_rotate(&(ps->head_a));
	}

}
//
//void    sorting_for(t_pushswap *ps)
//{
//
//}
//
//void    sorting_five(t_pushswap *ps)
//{
//
//}