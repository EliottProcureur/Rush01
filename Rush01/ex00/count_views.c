/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_views.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejacque <sejacque@student.42belgium.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 12:47:03 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/15 12:51:48 by sejacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 6
#define INNER 4

// Compte le nombre de batiment visible depuis la gauche
// Peut etre adapter pour le haut, le bas, la droite.
// Puis une fonction qui permet de check toutes les views en appelant toutes
// ces petites fonctions par exemple
int	count_left(int grid[SIZE][SIZE], int row)
{
	int col;
	int highest;
	int visible;

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