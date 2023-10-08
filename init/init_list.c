/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:18:53 by angela            #+#    #+#             */
/*   Updated: 2023/10/06 14:33:34 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



t_node *node_init()
{
    t_node *node;
    
    node = malloc(sizeof(t_node));
    if (node == NULL)
        return (NULL);
    node->next = NULL;
    return (node);
}


void init_list(t_pushswap *ps)
{
	int i = 0;
	t_node *previous_node_a = NULL;
	t_node *current_node_a;

	while (i < ps->number_numbers)
	{
		current_node_a = node_init();

		if (previous_node_a == NULL)
		{
			ps->head_a = current_node_a;
		}
		else
		{
			previous_node_a->next = current_node_a;
		}
		previous_node_a = current_node_a;
		i++;
	}
}




int fill_list_multi(t_pushswap *ps, char **av)
{
	t_node *current_node_a;
	int i;
	long nb;
	i = 1;
	current_node_a = ps->head_a;
	while (current_node_a != NULL && i <= ps->number_numbers)
	{
		nb = ft_atol(av[i]); 
		if (check_int_limit(nb)== 0)
			return (ERROR);
		current_node_a->data = nb ;
		current_node_a = current_node_a->next;
		i++;
	}
	return (SUCCESS);
}


int fill_list_mono(t_pushswap *ps)
{
	t_node *current_node_a;
	int i;
	int nb;

	i = 0;
	current_node_a = ps->head_a;
	while (current_node_a != NULL && i <= ps->number_numbers)
	{
		nb = ft_atol(ps->tab_args_number[i]);
		if (check_int_limit(nb)== 0)
			return (ERROR);
		current_node_a->data = nb;
		current_node_a = current_node_a->next;
		i++;
	}
	return SUCCESS;
}



void	free_structure(t_pushswap *ps)
{
    int i;

    if (ps->tab_args_number == NULL)
        return;
    i = -1;
    while (++i < ps->number_numbers)
    {
        if (ps->tab_args_number[i] != NULL)
        {
            free(ps->tab_args_number[i]);
            ps->tab_args_number[i] = NULL;
        }
    }
    if (ps->tab_args_number != NULL)
        free(ps->tab_args_number);
}

void free_nodes(t_node **head)
{
	t_node *current_node = *head;
	t_node *next_node;

	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}

	*head = NULL;
}
