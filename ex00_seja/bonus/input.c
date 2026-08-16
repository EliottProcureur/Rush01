/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejacque <sejacque@student.42belgium.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 10:43:07 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/16 15:24:37 by sejacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_clues(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!*str)
		return (0);
	while (str[i])
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || str[i] > '9')
				return (0);
			count++;
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	if (i % 2 == 0)
		return (0);
	return (count);
}

int	ft_get_size(int count, int *size)
{
	if (count % 4 != 0)
		return (0);
	*size = count / 4;
	if (*size < 4 || *size > 9)
		return (0);
	return (1);
}

int	ft_fill_clues(char *str, int *clues, int count, int size)
{
	int	i;

	i = 0;
	while (i < count)
	{
		clues[i] = str[i * 2] - '0';
		if (clues[i] > size)
			return (0);
		i++;
	}
	return (1);
}

int	ft_parse_input(char *str, int *clues, int *size)
{
	int	count;

	count = ft_count_clues(str);
	if (count == 0)
		return (0);
	if (!ft_get_size(count, size))
		return (0);
	if (!ft_fill_clues(str, clues, count, *size))
		return (0);
	return (1);
}
