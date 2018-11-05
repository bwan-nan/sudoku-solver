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

#include "../includes/validity.h"

int		is_revgrid_valid(char **tab, int position)
{
	int i;
	int j;
	int k;

	if (position == -1)
		return (1);
	i = position / 9;
	j = position % 9;
	if (tab[i][j] != '.')
		return (is_revgrid_valid(tab, position - 1));
	k = 1;
	while (k <= 9)
	{
		if (row_is_ok(k, tab, i) && column_is_ok(k, tab, j)
				&& nonet_is_ok(k, tab, i, j))
		{
			tab[i][j] = k + 48;
			if (is_revgrid_valid(tab, position - 1))
				return (1);
		}
		k++;
	}
	tab[i][j] = '.';
	return (0);
}
