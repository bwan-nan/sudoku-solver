/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:59:30 by bwan-nan          #+#    #+#             */
/*   Updated: 2018/09/09 19:33:00 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int		nonet_is_ok_check(int k, char **tab, int i, int j)
{
	int n_i;
	int n_j;
    int count;

    count = 0;
	n_i = 3 * (i / 3);
	n_j = 3 * (j / 3);
	i = n_i;
	j = n_j;
	while (j <= n_j + 2)
	{
		i = n_i;
		while (i <= n_i + 2)
		{
			if (tab[i][j] - 48 == k)
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

int     column_is_ok_check(int k, char **tab, int j)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (i <= 8)
    {
        if (tab[i][j] - 48 == k)
            count++;
        i++;
    }
    return (count);
}

int     row_is_ok_check(int k, char **tab, int i)
{
    int j;
    int count;

    count = 0;
    j = 0;
    while (j <= 8)
    {
        if (tab[i][j] - 48 == k)
            count++;
        j++;
    }
    return (count);
}


int		is_initial_grid_valid(char **tab, int position)
{
	int i;
	int j;
	int k;

	if (position == 9 * 9)
		return (1);
	i = position / 9;
	j = position % 9;
	if (tab[i][j] == '.')
		return (is_initial_grid_valid(tab, position + 1));
	k = tab[i][j] - 48;
	if ((!(row_is_ok_check(k, tab, i) == 1 && column_is_ok_check(k, tab, j) == 1 && nonet_is_ok_check(k, tab, i, j) == 1)))
	{
        ft_putstr("Erreur : Grille initiale invalide\n");
        return (0);
	}
    return(is_initial_grid_valid(tab, position + 1));
	return (1);
}
