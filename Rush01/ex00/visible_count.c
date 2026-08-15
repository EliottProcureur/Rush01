#include "rush01.h"

int visible_count(int *sol, int SIZE)
{
    int i;
    int max;
    int count;

    i = 1;
    max = sol[0];
    count = 1;
    while (i < SIZE)
    {
        if (sol[i] > max)
        {   
            max = sol[i];
            count++;
        }
        i++;
    }
    return (count);
}

/*
    Cette fonction compte combien de nombres sont visibles en partant du début d'une ligne ou colonne. Elle prend en paramètre 
    un tableau de 'size' entiers représentant une ligne ou une colonne et retourne le nombre de batiments visibles.
    Exemple :
    sol = {2, 3, 1, 4}
    visible_count(sol, 4) -> 3
    car : 2, 3, 4 sont visibles
*/