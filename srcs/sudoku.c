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

int		nonet_is_ok(int k, char **tab, int i, int j)
{
	int n_i;
	int n_j;

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
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int		column_is_ok(int k, char **tab, int j)
{
	int i;

	i = 0;
	while (i <= 8)
	{
		if (tab[i][j] - 48 == k)
			return (0);
		i++;
	}
	return (1);
}

int		row_is_ok(int k, char **tab, int i)
{
	int j;

	j = 0;
	while (j <= 8)
	{
		if (tab[i][j] - 48 == k)
			return (0);
		j++;
	}
	return (1);
}

int		is_grid_valid(char **tab, int position)
{
	int i;
	int j;
	int k;

	if (position == 9 * 9)
		return (1);
	i = position / 9;
	j = position % 9;
	if (tab[i][j] != '.')
		return (is_grid_valid(tab, position + 1));
	k = 1;
	while (k <= 9)
	{
		if (row_is_ok(k, tab, i) && column_is_ok(k, tab, j)
				&& nonet_is_ok(k, tab, i, j))
		{
			tab[i][j] = k + 48;
			if (is_grid_valid(tab, position + 1))
				return (1);
		}
		k++;
	}
	tab[i][j] = '.';
	return (0);
}
