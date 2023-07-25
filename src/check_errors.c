/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:13:27 by angela            #+#    #+#             */
/*   Updated: 2023/07/25 00:35:31 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int check_errors(int ac, char **av)
{
	if (ac > 2)
	{
		int	i;

		i = 0;
		while ( ++i < ac)
		{
			if ((check_isnumber(av[i])) == 0) // (!check_isnumber(av[i]))
				return(p_error());
			if (!check_int_limit(av[i]))
				return(p_error());
		}
	}
	// else if (ac == 2)
	// {
		
	// }
	// else
	// 	return (p_error());
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