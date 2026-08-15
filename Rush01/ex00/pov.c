int *pov(int obsv, int grid[SIZE][SIZE])
{
    int i;
    int j;
    int r[SIZE];

    i = 0;
    j = SIZE - 1;
    while(obsv >= 0 && obsv <= SIZE - 1 && i < SIZE)
    {
        r[i] = grid[i][obsv];
        i++;
    }
    while(obsv >= SIZE && obsv <= (2 * SIZE) - 1 && j >= 0)
    {
        r[i] = grid[i][obsv - SIZE];
        j--;
    }
    while(obsv >= (2 * SIZE) && obsv <= (3 * SIZE) - 1 && i < SIZE)
    {
        r[i] = grid[obsv - (2 * SIZE)][i];
        i++;
    }
    
    }
    while(obsv >= (3 * SIZE) && obsv <= (4 * SIZE) - 1 && j >= 0)
    {
        r[i] = grid[obsv - (3 * SIZE)][j];
        j--;
    }
    return r;
}

