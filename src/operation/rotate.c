/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:25:21 by angela            #+#    #+#             */
/*   Updated: 2023/08/05 18:59:23 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//fonction pour aller a la fin, retourne le dernier node

t_node	*last_node(t_node *head)
{
    if (!head)//secu si existe pas
        return (NULL);
    while (head->next != NULL) // tant que le pointeur du prochain n'est pas null, donc pas fin
        head = head->next; // passe au prochain
    return (head); //retourne l'adresse du node et pas du pointeur
}

//on va jusqu a la fin de la liste et on ajoute le 1er node
// [node1] -> [node2] -> [node3] -> [node4] -> [node5] avant <--- push
// [node2] <- [node3] <- [node4] <- [node5] <- [node1] apres
// le 1er devient dernier -> pour savoir lequel mettre a NULL
void    rotate_up(t_node **head)
//head correspond a 1er de la liste, first
{
    t_node *node_1;
    t_node *end;

    end = last_node(*head);
    node_1 = *head;// stocke le temps que le 1er change et c'est le node en soit qu'on deplace, node1.

    *head = (*head)->next; // move 1, on modifie directement la liste. 2nd ->1er

    end->next = node_1; // move 2, on avait stocké first pour ca. on pointe l'avant last sur le new last
    node_1->next = NULL; // move 3
    //end->data = node_1->data;

}


