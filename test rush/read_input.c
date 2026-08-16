/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elprocur <elprocur@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 15:41:44 by elprocur          #+#    #+#             */
/*   Updated: 2026/08/16 16:20:10 by elprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Renvoie le nombre d'indices trouvés dans 'argv[1]' (séparés par des espaces)
	Ex: "1 2 3 2 ..." -> nombre d'éléments (0 si erreur de format/argc)
*/
int	read_input(int argc, char **argv)
{
	int	i;
	int	counter;

	if (argc != 2)
		return (0);
	i = 0;
	counter = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == ' ')
			counter++;
		i++;
	}
	return (counter + 1);
}

/* Mappe le nombre total d'indices vers la dimension intérieure (inner)
   Ex: 16 indices -> inner = 4, 36 indices -> inner = 9
   Retourne 0 si nombre invalide
*/
int	redefine_size(int nbclues)
{
	if (nbclues == 16)
		return (4);
	else if (nbclues == 20)
		return (5);
	else if (nbclues == 24)
		return (6);
	else if (nbclues == 28)
		return (7);
	else if (nbclues == 32)
		return (8);
	else if (nbclues == 36)
		return (9);
	else
		return (0);
}

/* Modifications:
   - Réécriture pour renvoyer correctement le nombre d'indices et une
		fonction 'redefine_size' valide pour les tailles 4..9.
*/
