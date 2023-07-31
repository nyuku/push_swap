/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:18:53 by angela            #+#    #+#             */
/*   Updated: 2023/07/31 15:59:39 by angela           ###   ########.fr       */
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

void    print_nodes(t_pushswap *ps)// print la liste
{
	int i;
	t_node *current_node;

	current_node = ps->head;
	i = 0;
    while (current_node->next != NULL)
    {
        printf("node(%d)->data = %d\n", i, current_node->data);
		current_node = current_node->next;
		i++;
    }   
}

void    free_nodes(t_pushswap *ps)//fin di projet, llibere
{
	t_node *tmp;
	
    while (ps->head->next != NULL)
    {
		tmp = ps->head;
		tmp = ps->head->next;
		free(ps->head);
	}
	free(tmp);
	tmp = NULL;
}

void init_list(t_pushswap *ps)//madre, cree la liste
{
    int i;
    t_node *current_node;

    i = 0;
    current_node = node_init();//cree le tout premier node, random on le cree qq part
    ps->head = current_node;// enregistre l'adresse du node 1er et actuel
    while (i < ps->mono_arg)
    {
		current_node->next = node_init();
        current_node = current_node->next;
		i++;
    }
}


//on a une liste partant de 	
void fill_list(t_pushswap *ps)//recupere le tableau de char et transforme en int->list
{
	t_node *current_node;
	int i;

	i = 0;
	current_node = ps->head;
	while (current_node->next != NULL && i < ps->mono_arg)
	{
		current_node->data = ft_atoi(ps->tab_args_number[i]);
		// current_node->data = 0;

		current_node = current_node->next;
		i++;
	}
}