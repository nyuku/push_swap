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

/*C'est une fonction qui initialise la liste chainée
Elles vont recevoir les arguments données en entrée.*/

t_node *node_init()// un node a la fois, utils
{
    t_node *node;
    
    node = malloc(sizeof(t_node)); // cree un node
    if (node == NULL)
        return (NULL);
    node->next = NULL;
	//node->index = NULL;//new
	//node->data = NULL;
    return (node);
}


void init_list(t_pushswap *ps)
{
	int i = 0;
	t_node *previous_node_a = NULL;
	t_node *current_node_a;

	while (i < ps->number_numbers)
	{
		current_node_a = node_init(); // Create a new node

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

//
//void init_list(t_pushswap *ps)//madre, cree la liste, retour le head a?
//{
//        int i = 0;
//        t_node *previous_node_a = NULL;
//	    //t_node *previous_node_b = NULL;
//        t_node *current_node_a;
//        //t_node *current_node_b;// modifie en doublant tout
//
//
//        while (i <= ps->number_numbers)
//        {
//            current_node_a = node_init(); // Crée un nouveau nœud
//
//            if (previous_node_a == NULL)// || previous_node_b == NULL)// si on est au 1er node
//            {
//                ps->head_a = current_node_a; // Enregistre l'adresse du premier nœud
//
//            }
//            else
//            {
//                previous_node_a->next = current_node_a;// Relie le nœud précédent au nouveau nœud
//	            //previous_node_b->next = current_node_b;
//            }
//
//            previous_node_a = current_node_a; // Met à jour le nœud précédent, on avance
//	        //previous_node_b = current_node_b;
//	        i++;
//        }
//        //ps->tail = previous_node; // Enregistre l'adresse du dernier nœud
//        //il faut libérer la str qui a contenu les infos
//
//}

void	fill_list(t_pushswap *ps, char **av)//recupere le tableau de char et transforme en int->list
{
	t_node *current_node_a;
	int i;

	i = 0;
	current_node_a = ps->head_a;
    if (ps->multi_arg!= 0)//plusieur arg 
    {
        i = 1;
        while (current_node_a != NULL && i <= ps->number_numbers)// current_node_a -> next iciiiiiii
	    {
			current_node_a->data = ft_atoi(av[i]);
			current_node_a = current_node_a->next;
			i++;
	    }
    }
	//mono
	while (current_node_a != NULL && i < ps->number_numbers)// current_node_a -> next iciiiiiii
	{
		current_node_a->data = ft_atoi(ps->tab_args_number[i]);
		current_node_a = current_node_a->next;
		i++;
	}
	
}


int fill_list_multi(t_pushswap *ps, char **av)//retourn 0 si erreur
{
	t_node *current_node_a;
	int i;
	long nb;
	i = 1;// pourquoi pas a 0
	current_node_a = ps->head_a;// pour naviguer
	while (current_node_a != NULL && i < ps->number_numbers)// current_node_a -> next iciiiiiii
	{
		nb = ft_atol(av[i]); 
		if (check_int_limit(nb)== 0)
			return (ERROR);
		current_node_a->data = nb ;// plop
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
	while (current_node_a != NULL && i < ps->number_numbers)
	{
		nb = ft_atol(ps->tab_args_number[i]);
		current_node_a->data = nb;
		current_node_a = current_node_a->next;
//		current_node_a->next = NULL;
		i++;
	}
	return SUCCESS;
}



////on prend le seul argument qu'on a " plop plop plop"
//int fill_list_mono(t_pushswap *ps)//recupere le tableau de char et transforme en int->list
//{
//	t_node *current_node_a;
//	int i;
//	int nb;
//
//	i = 0;// naviguer dans le tableau
//	current_node_a = ps->head_a;
//	while (current_node_a != NULL && i < ps->number_numbers)// current_node_a -> next iciiiiiii
//	{
//		nb = ft_atol(ps->tab_args_number[i]);
//		// if (check_int_limit(nb) == 0)
//		// 	return (ERROR);
//		current_node_a->data = nb; // plop
//		//current_node_a->data = ft_atoi(ps->tab_args_number[i]);
//		current_node_a = current_node_a->next;
//		i++;
//	}
//	return (SUCCESS);
//}

void    fill_test(t_node **node, t_pushswap *ps)
{
	t_node *current;
	int i= 0;
	int n = 10;
	current = *node;
	while (current != NULL && i < ps->number_numbers)// current_node_a -> next iciiiiiii
	{
		current->data = n;
		current = current->next;
		i++;
		n++;
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

	*head = NULL; // Mettre à NULL pour indiquer que la liste est maintenant vide
}
