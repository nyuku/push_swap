/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:40:48 by angela            #+#    #+#             */
/*   Updated: 2023/07/25 00:13:16 by angela           ###   ########.fr       */
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
* 	structure
\*◇───────────────────────────────────────────────────────────────◇*/
typedef struct    s_node
{
    int          data;
    struct s_node *next;
}                t_node;




// typedef struct	Node
// {
//     int value;
//     struct Node* next;
// }				Node;

// typedef struct	List //list chainé
// {
//     Node* head;
//     Node* tail;
// }				List;


typedef struct	s_pushswap
{
    int number_arg;
    char **tab_args_number;
}				t_pushswap;


/*◇───────────────────────────────────────────────────────────────◇*\
* 	Prototypes funtions
\*◇───────────────────────────────────────────────────────────────◇*/
int check_mono_arg(char **av, t_pushswap *pushswap);
int check_if_number(char *str);
void	*ft_memset(void *p, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
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