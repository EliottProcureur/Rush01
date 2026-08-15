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

#define SIZE 6
#define INNER 4

int	ft_check_views(int grid[SIZE][SIZE]);

int	ft_can_place(int grid[SIZE][SIZE], int row, int col, int num)
{
	int	i;

	i = 1;
	while (i <= INNER)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	ft_solve(int grid[SIZE][SIZE], int row, int col)
{
	int	num;

	if (row == 5)
		return (ft_check_views(grid));
	if (col == 5)
		return (ft_solve(grid, row + 1, 1));
	num = 1;
	while (num <= INNER)
	{
		if (ft_can_place(grid, row, col, num))
		{
			grid[row][col] = num;
			if (ft_solve(grid, row, col + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
