/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elprocur <elprocur@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 10:43:07 by sejacque          #+#    #+#             */
/*   Updated: 2026/08/16 16:20:10 by elprocur         ###   ########.fr       */
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
		if (str[pos] < '1' || str[pos] > ('0' + inner))
			return (0);
		clues[i] = str[pos] - '0';
		if (i < clues_count - 1 && str[pos + 1] != ' ')
			return (0);
		i++;
	}
	return (str[(clues_count - 1) * 2 + 1] == '\0');
}

/* Modifications:
   - 'ft_parse_input' prend désormais 'clues_count' et 'inner' pour valider
		dynamiquement la longueur et la plage des valeurs (1..inner).
*/
