/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejacque <sejacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:28:54 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/15 21:02:30 by sejacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_views(int **grid, int size);
int	ft_count_left(int **grid, int size, int row);
int	ft_count_up(int **grid, int size, int col);

int	ft_can_place(int **grid, int size, int row, int col)
{
	int	i;

	i = 1;
	while (i <= size)
	{
		if ((i != col && grid[row][i] == grid[row][col])
			|| (i != row && grid[i][col] == grid[row][col]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_partial_views_ok(int **grid, int size, int row, int col)
{
	int	visible;

	visible = ft_count_left(grid, size, row);
	if (visible > grid[row][0] || visible + size - col < grid[row][0])
		return (0);
	visible = ft_count_up(grid, size, col);
	if (visible > grid[0][col] || visible + size - row < grid[0][col])
		return (0);
	return (1);
}

int	ft_solve(int **grid, int size, int row, int col)
{
	int	num;

	if (row == size + 1)
		return (ft_check_views(grid, size));
	if (col == size + 1)
		return (ft_solve(grid, size, row + 1, 1));
	num = 1;
	while (num <= size)
	{
		grid[row][col] = num;
		if (ft_can_place(grid, size, row, col))
		{
			if (ft_partial_views_ok(grid, size, row, col)
				&& ft_solve(grid, size, row, col + 1))
				return (1);
		}
		grid[row][col] = 0;
		num++;
	}
	return (0);
}
