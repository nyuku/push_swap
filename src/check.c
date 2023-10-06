#include "../includes/push_swap.h"

void check_all_arg(char **av, int ac, t_pushswap *ps)
{
    if (ac == 2)// un seul arguments
    {
        ps->mono_arg = check_mono_arg(av, ps); //stock dans notre variagle le nombre de chiffre
        if (ps->mono_arg == 0)
        {
            p_error();
            exit (0);
        }
    }
    else if (ac > 2)
    {
        ps->multi_arg = check_multi_arg(av, ac); 
        if (ps->multi_arg == 0)// un seul argument... appelle 2 x la fonction
        {
           //printf("multi,c'est que des nombres\n");
           /// ps->multi_arg = check_multi_arg(av, ac); //va verifier si elligible
            //printf("check_multi_arg d'arguments : %d\n", check_multi_arg(av, ac));
            //ft_free_str(ps->tab_args_number); ou pas
            //printf("c'est faux multi\n");

        }
        //fait quoi si ca marche
    }
}

//check si des nombres, retourne le nombre d'arguments. sinon return 0
int check_mono_arg(char **av, t_pushswap *ps)
{
    int i;
    int result;

    i = 0;
    result = 0;
    ps->tab_args_number = ft_split(av[1], ' '); // on utilise split pour isoler les nombres..et mettre dans un tableau
    //ici checl si un seul argument.
    // iciiii
    while (ps->tab_args_number[i]) // on parcout ce qu'on a obtenu pour verifier si c'est des nombres, case par case
    {
        if (check_if_number_str(ps->tab_args_number[i]) == 1)// check si nombre
        {
            result++;// donne le nombre de chiffre
            i++;
        }
        else
            return (0); // faudrait free dans l'appel
    }
    if (result == 0 || i == 1) // si aucun chiffre 
    {
        printf("marche po. il z a un seul arguement chiffre\n");
        return (0);
    }
    return (result);
}

//retourne 1 si ok
//on parcout la str pour verifier si c'est un nombre (!)au neg
int check_if_number_str(char *str)
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

int check_multi_arg(char **argv, int argc)// cherck chaque argument si c'est des nombre et renvoie combien il y en a
{
    int result;
    int i;

    result = 0;
    i = 1;
    while (i < argc)
    {
        if (check_if_number_str(argv[i]) == 1)
        {
            result++;
            i++;
        }
        else
            return (0);
    }
    return (result);
}
