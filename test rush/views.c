/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elprocur <elprocur@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 12:06:21 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/16 16:20:10 by elprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_INNER 9
#define MAX_SIZE 11
#define MAX_CLUES 36

int	ft_count_left(int grid[MAX_SIZE][MAX_SIZE], int row, int inner)
{
	int	col;
	int	highest;
	int	visible;

	col = 1;
	highest = 0;
	visible = 0;
	while (col <= inner)
	{
		if (grid[row][col] > highest)
		{
			highest = grid[row][col];
			visible++;
		}
		col++;
	}
	return (visible);
}

int	ft_count_right(int grid[MAX_SIZE][MAX_SIZE], int row, int inner)
{
	int	col;
	int	highest;
	int	visible;

	col = inner;
	highest = 0;
	visible = 0;
	while (col > 0)
	{
		if (grid[row][col] > highest)
		{
			highest = grid[row][col];
			visible++;
		}
		col--;
	}
	return (visible);
}

int	ft_count_up(int grid[MAX_SIZE][MAX_SIZE], int col, int inner)
{
	int	row;
	int	highest;
	int	visible;

	row = 1;
	highest = 0;
	visible = 0;
	while (row <= inner)
	{
		if (grid[row][col] > highest)
		{
			highest = grid[row][col];
			visible++;
		}
		row++;
	}
	return (visible);
}

int	ft_count_down(int grid[MAX_SIZE][MAX_SIZE], int col, int inner)
{
	int	row;
	int	highest;
	int	visible;

	row = inner;
	highest = 0;
	visible = 0;
	while (row > 0)
	{
		if (grid[row][col] > highest)
		{
			highest = grid[row][col];
			visible++;
		}
		row--;
	}
	return (visible);
}

int	ft_check_views(int grid[MAX_SIZE][MAX_SIZE], int inner)
{
	int	index;

	index = 1;
	while (index <= inner)
	{
		if (ft_count_up(grid, index, inner) != grid[0][index])
			return (0);
		if (ft_count_down(grid, index, inner) != grid[inner + 1][index])
			return (0);
		if (ft_count_left(grid, index, inner) != grid[index][0])
			return (0);
		if (ft_count_right(grid, index, inner) != grid[index][inner + 1])
			return (0);
		index++;
	}
	return (1);
}

/* Modifications:
		- Toutes les fonctions de comptage et 'ft_check_views' prennent désormais
			'inner' en paramètre pour supporter dynamiquement des grilles 4..9.
		- Les comparaisons avec les indices de bord utilisent 'inner
			+ 1' au lieu
			 d'une constante dure.
*/
