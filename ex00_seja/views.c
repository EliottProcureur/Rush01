/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejacque <sejacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 12:06:21 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/15 21:03:07 by sejacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 6
#define INNER 4

int	ft_count_left(int grid[SIZE][SIZE], int row)
{
	int	col;
	int	highest;
	int	visible;

	col = 1;
	highest = 0;
	visible = 0;
	while (col <= INNER)
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

int	ft_count_right(int grid[SIZE][SIZE], int row)
{
	int	col;
	int	highest;
	int	visible;

	col = INNER;
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

int	ft_count_up(int grid[SIZE][SIZE], int col)
{
	int	row;
	int	highest;
	int	visible;

	row = 1;
	highest = 0;
	visible = 0;
	while (row <= INNER)
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

int	ft_count_down(int grid[SIZE][SIZE], int col)
{
	int	row;
	int	highest;
	int	visible;

	row = INNER;
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

int	ft_check_views(int grid[SIZE][SIZE])
{
	int	index;

	index = 1;
	while (index <= INNER)
	{
		if (ft_count_up(grid, index) != grid[0][index])
			return (0);
		if (ft_count_down(grid, index) != grid[5][index])
			return (0);
		if (ft_count_left(grid, index) != grid[index][0])
			return (0);
		if (ft_count_right(grid, index) != grid[index][5])
			return (0);
		index++;
	}
	return (1);
}
