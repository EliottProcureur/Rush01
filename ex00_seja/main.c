/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejacque <sejacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 10:16:32 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/15 21:02:03 by sejacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SIZE 6
#define CLUES 16

int		ft_parse_input(char *str, int *clues);
void	ft_init_grid(int grid[SIZE][SIZE], int *clues);
int		ft_solve(int grid[SIZE][SIZE], int row, int col);
void	ft_print_grid(int grid[SIZE][SIZE]);

int	ft_print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	int	clues[CLUES];
	int	grid[SIZE][SIZE];

	if (argc != 2)
		return (ft_print_error());
	if (!ft_parse_input(argv[1], clues))
		return (ft_print_error());
	ft_init_grid(grid, clues);
	if (!ft_solve(grid, 1, 1))
		return (ft_print_error());
	ft_print_grid(grid);
	return (0);
}
