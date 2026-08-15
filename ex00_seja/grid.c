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

#define SIZE 6
#define INNER 4

void	ft_init_grid(int grid[SIZE][SIZE], int *clues)
{
	int	row;
	int	col;

	row = 0;
	while (row < SIZE)
	{
		col = 0;
		while (col < SIZE)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
	col = 0;
	while (col < INNER)
	{
		grid[0][col + 1] = clues[col];
		grid[5][col + 1] = clues[col + 4];
		grid[col + 1][0] = clues[col + 8];
		grid[col + 1][5] = clues[col + 12];
		col++;
	}
}

void	ft_print_grid(int grid[SIZE][SIZE])
{
	char	num;
	int		row;
	int		col;

	row = 1;
	while (row <= INNER)
	{
		col = 1;
		while (col <= INNER)
		{
			num = grid[row][col] + '0';
			write(1, &num, 1);
			if (col < INNER)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
