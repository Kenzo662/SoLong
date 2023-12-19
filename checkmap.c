#include "so_long.h"

int checkone(char *line)
{
    int i;

    i = 0;
    while(line[i])
    {
        if (line[i] != '1' && line[i] != '\n')
            return(1);
        i++;
    }
    return(0);
}

int CheckTopDown()
{
    int fd;
    char *line;
    int i;

    i = 0;
    fd = open("map.ber", O_RDONLY);
    line = get_next_line(fd);
    while(line[i])
    {
        if (line[i] != '1' && line[i] != '\n')
        {
            perror("La map n'est pas valide");
            exit(EXIT_FAILURE);
        }
    i++;
    }
    Checkline(i, fd, line);
    return (i);
}

int Checkline(int i, int fd, char *line)
{
    int bytes;
    int j;
    int countE;
    int countP;

    line = get_next_line(fd);
    countE = 0;
    countP = 0;
    printf("line = %s\n", line);
    while(checkone(line) != 0)
    {
        j = 0;
        if(line[0] != '1')
        {
            perror("La map n'est pas valide");
            exit(EXIT_FAILURE);
        }
        while(line[j])
        {
            if (line[j] != '1' && line[j] != '0' && line[j] != 'P' && line[j] != 'E' && line [j] != 'C' && line[j] != '\n')
            {
                perror("La map n'est pas valide1");
                exit(EXIT_FAILURE);
            }
            if (line[j] == 'E')
                countE++;
            if (line[j] == 'P')
                countP++; 
            if (countE > 1 || countP > 1)
            {
                perror("La map n'est pas valide2");
                exit(EXIT_FAILURE);
            }
            j++;
        }
        if (i != j)
        {
            perror("La map n'est pas valide3");
            exit(EXIT_FAILURE);
        }
        line = get_next_line(fd);
        printf("line = %s\n", line);
    }

}



int main(void)
{
    CheckTopDown();
}