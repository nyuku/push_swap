/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:13:27 by angela            #+#    #+#             */
/*   Updated: 2023/09/14 16:43:45 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

	int check_double(t_node *head)//modif et ajouer int max
	{
		t_node *temp;
		t_node *compare;

		temp = head;
		while (temp != NULL)
		{
			compare = temp->next; // Commence à partir du nœud suivant
			while (compare != NULL)
			{
				if (temp->data == compare->data)
					return ERROR; // Doublon détecté
				if (temp->data < -2147483648 || temp->data > 2147483647)
					return ERROR;
				compare = compare->next;
			}
				temp = temp->next;
		}
		return(SUCCESS);
	}
	
int	check_isnumber(char *str)
{
	int	i;
	
	i = -1;
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (ERROR);
	}
	return (SUCCESS);
}

int check_int_limit(char *str)
{
	long l;
	
	l = ft_atol(str);
	if (l <= INT_MIN || l >= INT_MAX)
		return(ERROR);
	return (SUCCESS);
}