/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejacque <sejacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 16:57:45 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/15 17:24:59 by sejacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_put_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (str[i] < '1' || str[i] > '9'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	is_valid_len(char *str)
{
	int	len;

	len = ft_strlen(str);
	printf("len = %d\n", len);
	if (len < 31 || len > 71)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (argc != 2)
		return (ft_put_error());
	if (ft_is_digit(argv[1]))
		return (ft_put_error());
	if (is_valid_len(argv[1]))
		return (ft_put_error());
	return (0);
}
