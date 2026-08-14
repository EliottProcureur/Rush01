/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejacque <sejacque@student.42belgium.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 23:50:44 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/15 00:44:02 by sejacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
#define RUSH01_H

#include <unistd.h>

#define CLUES 16
#define SIZE 6
#define INNER 4

int ft_put_error(void);
int ft_parse_clues(char *str, int clues[CLUES]);
void ft_init_grid(int grid[SIZE][SIZE], int clues[CLUES]);
void ft_print_grid(int grid[SIZE][SIZE]);

#endif
