#include "so_long.h"

/* int checkone(char *line)
{
    int i;

    i = 0;
    while(line[i])
    {
        if (line[i] != '1' && line[i])
            return(1);
        i++;
    }
    return(0);
} */

/* char  **CheckTopDown(char **map, int fd)
{
    int line;
    int i;

    i = 0;
    line = 0;
    data.map[line] = get_next_line(fd);
    while(map[line][i])
    {
        if (map[line][i] != '1' && data.map[line][i] != '\n')
        {
            perror("La map n'est pas valide");
            exit(EXIT_FAILURE);
        }
    i++;
    }
    return (Checkline(i, fd, data.map));
}

char  **Checkline(int i, int fd, char **map)
{
    int bytes;
    int j;
    int countE;
    int countP;
    int line;

    line = 0;
    data.map[line] = get_next_line(fd);
    countE = 0;
    countP = 0;
    bytes = 1;
    while(bytes == 1)
    {
        bytes = checkone(map[line]);
        if (bytes == 0)
            break;
        j = 0;
        if(map[line][0] != '1')
        {
            perror("La map n'est pas fermer");
            exit(1);
        }
        while(map[line][j])
        {
            if (map[line][j] != '1' && data.map[line][j] != '0' && data.map[line][j] != 'P' && data.map[line][j] != 'E' && data.map[line][j] != 'C' && data.map[line][j] != '\n')
            {
                perror("La map n'est pas valide");
                exit(1);
            }
            if (map[line][j] == 'E')
                countE++;
            if (map[line][j] == 'P')
                countP++; 
            if (countE > 1 || countP > 1)
            {
                perror("La map contient plusieurs sorties/joueurs");
                exit(1);
            }
            j++;
        }
        if(map[line][j - 1] != '\n')
            break;
        if (map[line][j - 2] != '1')
        {
            perror("La map n'est pas fermer");
            exit(1);
        }
        if (i != j)
        {
            perror("La map n'est pas rectangle");
            exit(1);
        }
        data.map[++line] = get_next_line(fd); 
    }
    j = ft_strlen(map[line]) + 1;
    if (checkone(map[line]) == 0 && i == j)
    {
            printf("La map est valide");
            return(map);
    }
    else 
        {
            perror("La map n'est pas valide");
            exit(1);
        }

} */



/* int main(void)
{
    int fd = open("map.ber", O_RDONLY);
    char *tab[10];
    CheckTopDown(tab, fd);
} */