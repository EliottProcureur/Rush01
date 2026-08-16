/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejacque <sejacque@student.42belgium.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 12:06:21 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/16 15:52:19 by sejacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_left(int **grid, int size, int row)
{
	int	col;
	int	highest;
	int	visible;

	col = 1;
	highest = 0;
	visible = 0;
	while (col <= size)
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

int	ft_count_right(int **grid, int size, int row)
{
	int	col;
	int	highest;
	int	visible;

	col = size;
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

int	ft_count_up(int **grid, int size, int col)
{
	int	row;
	int	highest;
	int	visible;

	row = 1;
	highest = 0;
	visible = 0;
	while (row <= size)
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

int	ft_count_down(int **grid, int size, int col)
{
	int	row;
	int	highest;
	int	visible;

	row = size;
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

int	ft_check_all_views(int **grid, int size)
{
	int	index;

	index = 1;
	while (index <= size)
	{
		if (ft_count_up(grid, size, index) != grid[0][index])
			return (0);
		if (ft_count_down(grid, size, index) != grid[size + 1][index])
			return (0);
		if (ft_count_left(grid, size, index) != grid[index][0])
			return (0);
		if (ft_count_right(grid, size, index) != grid[index][size + 1])
			return (0);
		index++;
	}
	return (1);
}
