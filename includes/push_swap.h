/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:40:48 by angela            #+#    #+#             */
/*   Updated: 2023/07/31 15:57:00 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>

# include "../libft/libft.h"
# include "ft_printf.h"

# define ERROR      0
# define SUCCESS    1

/*◇───────────────────────────────────────────────────────────────◇*\
* 	structure
\*◇───────────────────────────────────────────────────────────────◇*/
typedef struct    s_node
{
    int             data;
    struct s_node   *next;

}                t_node;


typedef struct	s_pushswap
{
    int     number_arg;
    char    **tab_args_number;
    int     multi_arg;
    int		mono_arg;
	t_node	*head;
	t_node	*tail;
}				t_pushswap;


/*◇───────────────────────────────────────────────────────────────◇*\
* 	Prototypes funtions
\*◇───────────────────────────────────────────────────────────────◇*/
int 	check_mono_arg(char **av, t_pushswap *ps);
int 	check_multi_arg(char **argv, int argc);
void 	check_all_arg(char **av, int ac, t_pushswap *ps);
int 	check_if_number(char *str);


void init_list(t_pushswap *ps);//madre
void fill_list(t_pushswap *ps);
void    print_nodes(t_pushswap *ps);
t_node *node_init();
void    free_nodes(t_pushswap *ps);

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