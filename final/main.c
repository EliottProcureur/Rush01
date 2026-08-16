/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejacque <sejacque@student.42belgium.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 10:16:32 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/16 18:30:38 by sejacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAX_SIZE 11
#define MAX_CLUES 36

int		ft_read_input(int argc, char **argv);
int		ft_redefine_size(int nbclues);
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
	int	clues[MAX_CLUES];
	int	grid[MAX_SIZE][MAX_SIZE];

	nbclues = ft_read_input(argc, argv);
	if (nbclues == 0)
		return (ft_print_error());
	inner = ft_redefine_size(nbclues);
	if (inner == 0)
		return (ft_print_error());
	if (!ft_parse_input(argv[1], clues, nbclues, inner))
		return (ft_print_error());
	ft_init_grid(grid, clues, inner);
	if (!ft_solve(grid, 1, 1, inner))
		return (ft_print_error());
	ft_print_grid(grid, inner);
	return (0);
}
