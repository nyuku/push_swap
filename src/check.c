#include "../includes/push_swap.h"

void check_all_arg(char **av, int ac, t_pushswap *ps)
{
    if (ac == 2)
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
        if (ps->multi_arg == 0)
        {
			if (ps->tab_args_number != NULL)
	            ft_free_double_str(ps->tab_args_number);
			p_error();
			exit (0);
        }
    }
}

int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

int check_mono_arg(char **av, t_pushswap *ps)
{
//	if (!check_if_number_str(av[1])) //couac
//		return (0);
	int i;

	i = 0;
	ps->number_numbers = count_words(av[1], ' ');
	if (ps->number_numbers == 1)
		return (0);// ou pas error/..!
    ps->tab_args_number = ft_split(av[1], ' ');
	while (i < ps->number_numbers)
	{
		if (!check_if_number_str(ps->tab_args_number[i]))
		{
			ft_free_double_str(ps->tab_args_number);
			return (0);
		}
		i++;//couac
	}
		return (1);
	ps->number_numbers = ps->mono_arg;
	return (ps->number_numbers);
}

int check_if_number_str(char *str)
{
    int i;

    i = 0;
    if (!str[i])
        return (0);
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] != '\0')
    {
        if ((str[i] >= '0' && str[i] <= '9'))
            i++;
        else
            return (0);
    }
    return (1);
}

int check_multi_arg(char **argv, int argc)
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
