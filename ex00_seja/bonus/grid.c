/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejacque <sejacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 23:42:18 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/15 20:58:31 by sejacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_init_grid(int **grid, int *clues, int size)
{
	int	row;
	int	col;

	row = 0;
	while (row < size + 2)
	{
		col = 0;
		while (col < size + 2)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
	col = 0;
	while (col < size)
	{
		grid[0][col + 1] = clues[col];
		grid[size + 1][col + 1] = clues[col + size];
		grid[col + 1][0] = clues[col + size * 2];
		grid[col + 1][size + 1] = clues[col + size * 3];
		col++;
	}
}

void	ft_print_grid(int **grid, int size)
{
	char	num;
	int		row;
	int		col;

	row = 1;
	while (row <= size)
	{
		col = 1;
		while (col <= size)
		{
			num = grid[row][col] + '0';
			write(1, &num, 1);
			if (col < size)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
