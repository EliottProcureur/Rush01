/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejacque <sejacque@student.42belgium.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 23:50:24 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/15 00:43:34 by sejacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int ft_put_error(void)
{
    write(2, "Error\n", 6);
    return (1);
}

int ft_parse_clues(char *str, int clues[CLUES])
{
    int i;

    i = 0;
    while (i < 16)
    {
        if (str[i * 2] < '1' || str[i * 2] > '4')
            return (0);
        clues[i] = str[i * 2] - '0';
        if (i < 15 && str[i * 2 + 1] != ' ')
            return (0);
        i++;
    }
    if (str[31] != '\0')
        return (0);
    return (1);
}

void ft_init_grid(int grid[SIZE][SIZE], int clues[CLUES])
{
    (void)grid;
    (void)clues;
    // loop to init INNER size of the grid to 0
    // we init full row and col from inner size to 0
    // 2 while loops to init grid[row][col]
    //
    // reset col counter and  loop again while col < INNER size 
    // to take the clues and put them around the inner grid
    //
}

int main(int argc, char **argv)
{
    int clues[CLUES];
    int grid[SIZE][SIZE];

    if (argc != 2)
        return (ft_put_error());
    if (!ft_parse_clues(argv[1], clues))
            return(ft_put_error());
    ft_init_grid(grid, clues);
    //if (!ft_solve_grid(grid, 1, 1))
    //    return (ft_put_error());
    //ft_print_grid(grid);
    return (0);
}
