/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejacque <sejacque@student.42belgium.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 10:16:32 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/16 15:40:50 by sejacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_count_clues(char *str);
int		ft_get_size(int count, int *size);
int		ft_parse_input(char *str, int *clues, int *size);
void	ft_init_grid(int **grid, int *clues, int size);
int		ft_solve(int **grid, int size, int row, int col);
void	ft_print_grid(int **grid, int size);

int	ft_print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	ft_free_for_all(int *clues, int **grid, int size, int error)
{
	int	row;

	row = 0;
	if (grid)
	{
		while (row < size + 2)
		{
			if (grid[row])
				free(grid[row]);
			row++;
		}
		free(grid);
	}
	if (clues)
		free(clues);
	if (error)
		return (ft_print_error());
	return (0);
}

int	**ft_create_grid(int size)
{
	int	**grid;
	int	row;

	grid = (int **)malloc((size + 2) * sizeof(*grid));
	if (!grid)
		return (NULL);
	row = 0;
	while (row < size + 2)
	{
		grid[row] = (int *)malloc((size + 2) * sizeof(**grid));
		if (!grid[row])
		{
			while (row > 0)
			{
				row--;
				free(grid[row]);
			}
			free(grid);
			return (NULL);
		}
		row++;
	}
	return (grid);
}

int	*ft_alloc_input(char *str, int *size)
{
	int	count;
	int	*clues;

	count = ft_count_clues(str);
	if (count == 0)
		return (NULL);
	if (!ft_get_size(count, size))
		return (NULL);
	clues = (int *)malloc(count * sizeof(*clues));
	if (!clues)
		return (NULL);
	if (!ft_parse_input(str, clues, size))
	{
		free(clues);
		return (NULL);
	}
	return (clues);
}

int	main(int argc, char **argv)
{
	int	*clues;
	int	**grid;
	int	size;

	if (argc != 2)
		return (ft_print_error());
	grid = NULL;
	clues = ft_alloc_input(argv[1], &size);
	if (!clues)
		return (ft_print_error());
	grid = ft_create_grid(size);
	if (!grid)
		return (ft_free_for_all(clues, grid, size, 1));
	ft_init_grid(grid, clues, size);
	if (!ft_solve(grid, size, 1, 1))
		return (ft_free_for_all(clues, grid, size, 1));
	ft_print_grid(grid, size);
	ft_free_for_all(clues, grid, size, 0);
	return (0);
}
