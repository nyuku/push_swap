/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:18:53 by angela            #+#    #+#             */
/*   Updated: 2023/08/03 17:26:44 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*C'est une fonction qui initialise la liste chainée
Elles vont recevoir les arguments données en entrée.*/

t_node *node_init()// un node a la fois, utils
{
    t_node *node;
    
    node = malloc(sizeof(t_node)); // cree un node
    if (node == NULL)
        return (NULL);
    node->next = NULL;
    return (node);
}

void init_list(t_pushswap *ps)//madre, cree la liste
   {
        int i = 0;
        t_node *previous_node = NULL;
        t_node *current_node;


        while (i < ps->number_numbers)
        {
            current_node = node_init(); // Crée un nouveau nœud
            current_node->next = NULL; // Initialise next à NULL

            if (previous_node == NULL)
            {
                ps->head_a = current_node; // Enregistre l'adresse du premier nœud
            }
            else
            {
                previous_node->next = current_node; // Relie le nœud précédent au nouveau nœud
            }

            previous_node = current_node; // Met à jour le nœud précédent
            i++;
        }
        ps->tail = previous_node; // Enregistre l'adresse du dernier nœud
    }




//on a une liste partant de 	
void	fill_list(t_pushswap *ps)//recupere le tableau de char et transforme en int->list
{
	t_node *current_node;
	int i;

	i = 0;
	current_node = ps->head_a;
	while (current_node != NULL && i < ps->number_numbers)// current_node -> next iciiiiiii
	{
		current_node->data = ft_atoi(ps->tab_args_number[i]);
		current_node = current_node->next;
		i++;
	}
	
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

void    free_nodes(t_pushswap *ps)//fin di projet, llibere
{
    t_node *tmp;

    while (ps->head_a->next != NULL)
    {
        if (ps->head_a != NULL)
        {
            tmp = ps->head_a;
            tmp = ps->head_a->next;
            free(ps->head_a);
            ps->head_a = tmp;
        }
    }
    free(tmp);
    tmp = NULL;
}
