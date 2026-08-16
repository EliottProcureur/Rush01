/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejacque <sejacque@student.42belgium.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:28:54 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/16 18:29:06 by sejacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_SIZE 11

int	ft_check_views(int grid[MAX_SIZE][MAX_SIZE], int inner);

int	ft_can_place(int grid[MAX_SIZE][MAX_SIZE], int row, int col, int inner)
{
	int	i;
	int	num;

	num = grid[row][col];
	i = 1;
	while (i <= inner)
	{
		if ((i != col && grid[row][i] == num)
			|| (i != row && grid[i][col] == num))
			return (0);
		i++;
	}
	return (1);
}

int	ft_solve(int grid[MAX_SIZE][MAX_SIZE], int row, int col, int inner)
{
	int	num;

	if (row == inner + 1)
		return (ft_check_views(grid, inner));
	if (col == inner + 1)
		return (ft_solve(grid, row + 1, 1, inner));
	num = 1;
	while (num <= inner)
	{
		grid[row][col] = num;
		if (ft_can_place(grid, row, col, inner))
		{
			if (ft_solve(grid, row, col + 1, inner))
				return (1);
		}
		grid[row][col] = 0;
		num++;
	}
	return (0);
}
