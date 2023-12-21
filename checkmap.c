#include "so_long.h"

int checkone(char *line)
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
}

int CheckTopDown(char **map)
{
    int fd;
    int line;
    int i;

    i = 0;
    fd = open("map.ber", O_RDONLY);
    line = 0;
    map[line] = get_next_line(fd);
    while(map[line][i])
    {
        if (map[line][i] != '1' && map[line][i] != '\n')
        {
            perror("La map n'est pas valide");
            exit(EXIT_FAILURE);
        }
    i++;
    }
    Checkline(i, fd, map);
}

char  **Checkline(int i, int fd, char **map)
{
    int bytes;
    int j;
    int countE;
    int countP;
    int line;

    line = 0;
    map[line] = get_next_line(fd);
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
            perror("La map n'est pas valide");
            exit(EXIT_FAILURE);
        }
        while(map[line][j])
        {
            if (map[line][j] != '1' && map[line][j] != '0' && map[line][j] != 'P' && map[line][j] != 'E' && map[line][j] != 'C' && map[line][j] != '\n')
            {
                perror("La map n'est pas valide1");
                exit(EXIT_FAILURE);
            }
            if (map[line][j] == 'E')
                countE++;
            if (map[line][j] == 'P')
                countP++; 
            if (countE > 1 || countP > 1)
            {
                perror("La map n'est pas valide2");
                exit(EXIT_FAILURE);
            }
            j++;
        }
        if(map[line][j - 1] != '\n')
            break;
        if (map[line][j - 2] != '1')
        {
            perror("La map n'est pas fermer");
            exit(EXIT_FAILURE);
        }
        if (i != j)
        {
            perror("La map n'est pas rectangle");
            exit(EXIT_FAILURE);
        }
        map[++line] = get_next_line(fd); 
    }
    if (checkone(map[line]) == 0)
            return(map);
    else 
        {
            perror("La map n'est pas valide6");
            exit(EXIT_FAILURE);
        }

}



int main(void)
{
    char *tab[10];
    CheckTopDown(tab);
}