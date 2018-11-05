/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 19:00:06 by bwan-nan          #+#    #+#             */
/*   Updated: 2018/09/09 19:39:44 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/includes.h"

int		main(int ac, char **av)
{
	int	i;
	int	k;
	int     j;
	char	*tab[9];
	char    tmp[9][9];
	char    **tabrev;

	if (ac == 1)
		return (0);
	if (ac != 10)
	{
		ft_putstr("Error : you should only input a 9x9 grid.\n");
		return (0);
	}
	i = 1;
	k = 0;
	if (!(tabrev = malloc(sizeof(char*) * 9)))
		return (0);
	while (k <= 8)
	{
		if (!(tabrev[k] = malloc(sizeof(char) * 9)))
			return (0);
		k++;
	}
	k = 0;
	while (i != ac)
	{
		tab[k] = av[i];
		j = 0;
		while (av[i][j])
		{
			tmp[k][j] = av[i][j];
			j++;
		}
		tabrev[k] = tmp[k];
		i++;
		k++;
	}
	ft_putstr("Initial grid\n");
	print_sudoku(tab);
	write(1, "\n\n", 2);
	if (error(tab))
		return (0);
	if (is_initial_grid_valid(tab, 0) == 0)
		return (0);
	if (is_grid_valid(tab, 0) == 0)
	{
		ft_putstr("Error: this sudoku cannot be solved.\n");
		return (0);
	}
	is_revgrid_valid(tabrev, 80);
	if (diff(tab, tabrev))
		return (0);
	free(tabrev);
	ft_putstr("Solution:\n");
	print_sudoku(tab);
	return (0);
}
