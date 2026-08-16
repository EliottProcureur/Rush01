/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elprocur <elprocur@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 10:16:32 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/16 16:20:10 by elprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAX_INNER 9
#define MAX_SIZE 11
#define MAX_CLUES 36

int		read_input(int argc, char **argv);
int		redefine_size(int nbclues);

int		ft_parse_input(char *str, int *clues, int clues_count, int inner);
void	ft_init_grid(int grid[MAX_SIZE][MAX_SIZE], int *clues, int inner);
int		ft_solve(int grid[MAX_SIZE][MAX_SIZE], int row, int col, int inner);
void	ft_print_grid(int grid[MAX_SIZE][MAX_SIZE], int inner);

int	ft_print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	int	nbclues;
	int	inner;
	int	clues_count;
	int	clues[MAX_CLUES];
	int	grid[MAX_SIZE][MAX_SIZE];

	nbclues = read_input(argc, argv);
	if (nbclues == 0)
		return (ft_print_error());
	inner = redefine_size(nbclues);
	if (inner < 4 || inner > MAX_INNER)
		return (ft_print_error());
	clues_count = inner * 4;
	if (!ft_parse_input(argv[1], clues, clues_count, inner))
		return (ft_print_error());
	ft_init_grid(grid, clues, inner);
	if (!ft_solve(grid, 1, 1, inner))
		return (ft_print_error());
	ft_print_grid(grid, inner);
	return (0);
}

/* Modifications:
	- Détermination dynamique de 'inner' via 'read_input' + 'redefine_size'.
	- Appels aux fonctions mis à jour pour accepter 'inner' et 'clues_count'.
*/
