/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:25:21 by angela            #+#    #+#             */
/*   Updated: 2023/08/05 18:59:23 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void swap(t_node **node)//donne le 1er node 
{
    if (*node == NULL || (*node)->next == NULL)
        return;
	// [node 1] -> [node2]-> [node3] avant
	// [node 2] -> [node1]-> [node3] apres
	//l'addresse d'un noeud...et le pointeur de celui avant sauf pour le 1er
	
	//init node1 et node 2 sont des temp
    t_node *node1 = *node;
    t_node *node2 = (*node)->next;
	
	//[node1]-> [node3]
	//le pointeur de node-1 recupere le pointeur next de node-2(le node 3)
    node1->next = node2->next;
	
	//[node 2] -> [node1]
	//le pointeur de node-2 pointe vers le noeud 1(son adresse)
    node2->next = node1;
    *node = node2;
}

void double_swap(t_node **node_a, t_node **node_b)
{
    swap(node_a);
    swap(node_b);
}
