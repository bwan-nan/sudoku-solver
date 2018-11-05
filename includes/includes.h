#ifndef INCLUDES_H
# define INCLUDES_H

void    ft_putchar(char c);
void    ft_putstr(char *str);
void    print_sudoku(char **tab);
int     diff(char **tab, char **tabrev);
int     error(char **tab);
int     is_initial_grid_valid(char **tab, int position);
int     is_grid_valid(char **tab, int position);
int     is_revgrid_valid(char **tab, int position);


#endif
