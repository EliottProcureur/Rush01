#include <unistd.h>


int ft_strlen(char *str);



// 4x4 = "1 2y3 4 1 2 3 4 1 2 3k4 1 2 p 4"
int is_valid_len(char *str)
{
    int len;

    len = ft_strlen(str);
    if (len < 31 || len > 71)
        return (1);
    return (0);
}

int is_valid_nbr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
         i++;
    }
    return (i);
}

int nbr_nbr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}