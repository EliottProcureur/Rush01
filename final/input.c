/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejacque <sejacque@student.42belgium.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 10:43:07 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/16 18:28:44 by sejacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_parse_input(char *str, int *clues, int clues_count, int inner)
{
	int	i;
	int	pos;

	i = 0;
	while (i < clues_count)
	{
		pos = i * 2;
		if (str[pos] < '1' || str[pos] > '0' + inner)
			return (0);
		clues[i] = str[pos] - '0';
		if (i + 1 < clues_count && str[pos + 1] != ' ')
			return (0);
		i++;
	}
	return (str[clues_count * 2 - 1] == '\0');
}

int	ft_read_input(int argc, char **argv)
{
	int	i;
	int	count;

	if (argc != 2 || argv[1][0] == '\0')
		return (0);
	i = 0;
	count = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] < '1' || argv[1][i] > '9')
			return (0);
		count++;
		i++;
		if (argv[1][i] == '\0')
			break ;
		if (argv[1][i] != ' ')
			return (0);
		i++;
	}
	return (count);
}

int	ft_redefine_size(int nbclues)
{
	if (nbclues >= 16 && nbclues <= 36 && nbclues % 4 == 0)
		return (nbclues / 4);
	return (0);
}
