#include <unistd.h>

void print_solution(int *solution)
{
    int i = 0;

    while (i < 16)
    {
        if (i != 0 && i % 4 == 0)
            write(1, "\n", 1);

        char c = solution[i] + '0';
        write(1, &c, 1);    
        write(1, " ", 1);
        i++;
    }
    write(1, "\n", 1);
}

/*
    Cette fonction affiche la solution d'un puzzle de 4x4. Elle prend en paramètre un tableau de 16 entiers représentant la solution 
    et affiche chaque ligne de la solution sur une nouvelle ligne, avec les nombres séparés par des espaces.
    Exemple :
    solution = {1, 2, 3, 4, 2, 3, 4, 1, 3, 4, 1, 2, 4, 1, 2, 3}
    print_solution(solution) affichera :
    1 2 3 4 
    2 3 4 1 
    3 4 1 2 
    4 1 2 3
*/