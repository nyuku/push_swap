/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:40:48 by angela            #+#    #+#             */
/*   Updated: 2023/06/25 17:08:05 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"
# include "ft_printf.h"

# define ERROR      0
# define SUCCESS    1

/*◇───────────────────────────────────────────────────────────────◇*\
* 	check_error.c
\*◇───────────────────────────────────────────────────────────────◇*/
int check_errors(int ac, char **av);
int	check_isnumber(char *str);
int check_int_limit(char *str);

/*◇───────────────────────────────────────────────────────────────◇*\
* 	utils.c
\*◇───────────────────────────────────────────────────────────────◇*/
int p_error();
long	ft_atol(const char *nptr);

#endif