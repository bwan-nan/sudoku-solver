/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 19:30:55 by bwan-nan          #+#    #+#             */
/*   Updated: 2018/09/09 19:34:39 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	print_sudoku(char **tab)
{
	int j;
	int i;

	i = 0;
	while (i <= 8)
	{
		j = 0;
		while (j <= 8)
		{
			ft_putchar(tab[i][j]);
			if (j == 8)
				ft_putchar('\n');
			else
				ft_putchar(' ');
			j++;
		}
		i++;
	}
}
