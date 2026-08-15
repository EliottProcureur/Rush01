/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_old.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejacque <sejacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 23:50:24 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/15 16:58:57 by sejacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define CLUES 16
#define SIZE 6
#define INNER 4

int nbr_nbr(char *str);
int ft_is_digit(char *str);



int ft_parse_clues(char *str, int *clues, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (str[i * 2] < '1' || str[i * 2] > '4')
            return (0);
        clues[i] = str[i * 2] - '0';
        if (i < size - 1 && str[i * 2 + 1] != ' ')
            return (0);
        i++;
    }
    if (str[31] != '\0')
        return (0);
    return (1);
}

// int clues[CLUES]
// char str[16];
/*void ft_init_grid(int grid[SIZE][SIZE], int clues[CLUES])
{
    int row;
    int col;

    row = 0;
    col = 0;
    while (row < SIZE)
    {
        grid[row][col + 1];
        grid[][] = clues[][];
        row++;
    }
}*/

void ft_print_clues(int *clues, int size)
{
    int i;
    char bref;

    i = 0;
    while (i < size)
    {
        bref = clues[i] + '0';
        write(1, &bref, 1);
        i++;
    }
    
}

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

int main(int argc, char **argv)
{
    int *clues;
    // int grid[SIZE][SIZE];
    int count;

    (void)clues;
    (void)count;
    if (argc != 2)
        return (ft_put_error());
    if (ft_is_digit(argv[1]))
        return (ft_put_error());
    // count = nbr_nbr(argv[1]);
    // clues = (int *)malloc(count * sizeof(int));
    // if (!clues)
    //     return (ft_put_error());
    
    // if (!ft_parse_clues(argv[1], clues, count))
    //         return(ft_put_error());
    // ft_print_clues(clues, 16);
    // ft_init_grid(grid, clues);
    //if (!ft_solve_grid(grid, 1, 1))
    //    return (ft_put_error());
    //ft_print_grid(grid);
    // free(clues);
    return (0);
}
