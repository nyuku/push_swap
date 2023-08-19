/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:40:48 by angela            #+#    #+#             */
/*   Updated: 2023/08/03 15:11:30 by angela           ###   ########.fr       */
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
	int             index;
    struct s_node   *next;

}                t_node;


typedef struct	s_pushswap
{
    //int     number_arg;
    char    **tab_args_number;
    int     multi_arg;
    int		mono_arg;
    int     number_numbers;
	int     nombre_op;

	t_node	*head_a;
    t_node	*head_b;
	t_node  *biggest;

//	t_node	*tail;
//    t_node  *stack_a;
//    int     size_a;
//    t_node  *stack_b;
//    int     size_b;
    
}				t_pushswap;


/*◇───────────────────────────────────────────────────────────────◇*\
* 	Prototypes funtions
\*◇───────────────────────────────────────────────────────────────◇*/
int 	check_mono_arg(char **av, t_pushswap *ps);
int 	check_multi_arg(char **argv, int argc);
void 	check_all_arg(char **av, int ac, t_pushswap *ps);
int 	check_if_number(char *str);


void    init_list(t_pushswap *ps);//madre
void    fill_list(t_pushswap *ps);
void    print_nodes(t_node **node, char c);
t_node  *node_init();
void    free_nodes(t_node **head);

void print_list(t_node *head, char c);
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
void	free_structure(t_pushswap *ps);
int    list_size(t_node *node);
void    fill_test(t_node **node, t_pushswap *ps);
void    index_node(t_pushswap *ps);
void    find_biggest(t_pushswap *ps);
/*◇───────────────────────────────────────────────────────────────◇*\
* 	Rules
\*◇───────────────────────────────────────────────────────────────◇*/
void    swap(t_node **node,t_pushswap *ps);
void    rotate_up(t_node **head,t_pushswap *ps);
void    reverse_rotate(t_node **head,t_pushswap *ps);
void    push(t_node **origin, t_node **destination,t_pushswap *ps);
void    double_swap(t_node **node_a, t_node **node_b,t_pushswap *ps);
void    double_rotate(t_node **node_a,t_node **node_b, t_pushswap *ps);
void    double_reverse_rotate(t_node **node_a,t_node **node_b, t_pushswap *ps);
/*◇───────────────────────────────────────────────────────────────◇*\
* 	Liste
\*◇───────────────────────────────────────────────────────────────◇*/
t_node	*last_node(t_node *head);
/*◇───────────────────────────────────────────────────────────────◇*\
* 	algo
\*◇───────────────────────────────────────────────────────────────◇*/
void    threesome(t_pushswap *ps, int sorting_for);
void    sorting_for(t_pushswap *ps,  int five_sort);
void    sorting_five(t_pushswap *ps);
void    small_sorting(t_pushswap *ps);
void    duo(t_pushswap *ps);


#endif