#include "../includes/includes.h"


int     diff(char **tab, char **tabrev)
{
    int i;
    int j;

    i = 0;
    while (i < 9)
    {
        j = 0;
        while (tab[i][j])
        {
             if (tab[i][j] != tabrev[i][j])
            {
                ft_putstr("Error: there is more than one solution .\n\nDescending solution : \n");
                print_sudoku(tab);
                ft_putstr("\n\nAscending solution:\n");
                print_sudoku(tabrev);
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int     error(char **tab)
{
    int i;
    int j;

    i = 0;
    while (i < 9)
    {
        if (ft_strlen(tab[i]) != 9)
        {
            ft_putstr("Error: you should only input a 9x9 grid.\n");
            return (1);
        }
        j = 0;
        while (tab[i][j])
        {
            if (!((tab[i][j] >= 49 && tab[i][j] <= 57) || tab[i][j] == '.'))
            {
                ft_putstr("Error: you should have your input composed only by digits or dots.\n");
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

