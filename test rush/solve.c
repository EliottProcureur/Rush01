/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elprocur <elprocur@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 11:28:54 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/16 16:26:59 by elprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_INNER 9
#define MAX_SIZE 11
#define MAX_CLUES 36

int	ft_check_views(int grid[MAX_SIZE][MAX_SIZE], int inner);

int	ft_can_place(int grid[MAX_SIZE][MAX_SIZE], int row, int col, int num,
	int inner)
{
	int	i;

	i = 1;
	while (i <= inner)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

/* Modifications:
	- Les fonctions acceptent maintenant 'inner' en paramètre pour supporter
		des grilles de côté 'inner' entre 4 et 9.
	- Utilisation de 'MAX_SIZE' pour la taille statique maximale des tableaux.
*/

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
		if (ft_can_place(grid, row, col, num, inner))
		{
			grid[row][col] = num;
			if (ft_solve(grid, row, col + 1, inner))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
