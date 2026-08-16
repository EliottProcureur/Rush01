/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejacque <sejacque@student.42belgium.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 23:42:18 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/16 18:24:50 by sejacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAX_SIZE 11

void	ft_init_grid(int grid[MAX_SIZE][MAX_SIZE], int *clues, int inner)
{
	int	row;
	int	col;

	row = 0;
	while (row < MAX_SIZE)
	{
		col = 0;
		while (col < MAX_SIZE)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
	col = 0;
	while (col < inner)
	{
		grid[0][col + 1] = clues[col];
		grid[inner + 1][col + 1] = clues[inner + col];
		grid[col + 1][0] = clues[2 * inner + col];
		grid[col + 1][inner + 1] = clues[3 * inner + col];
		col++;
	}
}

void	ft_print_grid(int grid[MAX_SIZE][MAX_SIZE], int inner)
{
	char	num;
	int		row;
	int		col;

	row = 1;
	while (row <= inner)
	{
		col = 1;
		while (col <= inner)
		{
			num = grid[row][col] + '0';
			write(1, &num, 1);
			if (col < inner)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
