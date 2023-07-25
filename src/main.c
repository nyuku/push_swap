/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:19:08 by angela            #+#    #+#             */
/*   Updated: 2023/07/25 13:30:18 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include<stdio.h>

int	main(int ac, char **av)
{
	t_pushswap pushswap;

	// if (check_errors(ac, av) == ERROR); // or "if (!check_errors(ac, av)) return (0);"
	// 	return (ERROR);
	if (ac == 2)
	{
		if (check_mono_arg(av, &pushswap) != 0)
		{
			printf("c'est que des nombres\n");
			printf("nombre d'arguments : %d\n", check_mono_arg(av, &pushswap));
		}
		
		else 
			printf("c'est faux\n");
	}
	else
		return (0);// un seul argument	
}

//check si des nombres, retourne le nombre d'arguments. sinon return 0
int check_mono_arg(char **av, t_pushswap *pushswap)
{
	int i;
	int result;
	
	i = 0;
	result = 0;
	pushswap->tab_args_number = ft_split(av[1], ' '); // on utilise split pour isoler les nombres
	//ici checl si un seul argument.
	
	while (pushswap->tab_args_number[i]) // on parcout ce qu'on a obtenu pour verifier si c'est des nombres, case par case
	{
		if (check_if_number(pushswap->tab_args_number[i]) == 1)
		{
			result++;
			i++;
		}
		else
			return (0);
	}
	if (result == 0 || i == 1)
	{
		printf("marche po. il z a un seul arguement chiffre\n");
		return (0);
	}
		
	return (result);
}

//retourne 1 si ok
//on parcout la str pour verifier si c'est un nombre (!)au neg
int check_if_number(char *str)
{
	int i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}