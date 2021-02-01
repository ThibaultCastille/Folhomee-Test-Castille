/*
** FOLHOMEE PROJECT, 2021
** ex03
** File description:
** Folhomee_project
*/

#include "include/ex03.h"

#define MAXCHAR 1000

int extract_numbers(char *stock) { // fonction qui extrait les nombres
    int final = 0;
    char *p = stock;

    for (; *p;) {
        if (isdigit(*p))
            final = strtol(p, &p, 10);
        else
            p++;
    }
    return (final);
}

void init(sys_t *sys) { // fonction d'inititalisation des variables importantes
    sys->nord = 0;
    sys->sud = 0;
    sys->est = 0;
    sys->ouest = 0;
    sys->direction = 'E';
}

int main(int ac, char **av) {
    sys_t *sys = malloc(sizeof(sys_t));
    FILE *fp = fopen(av[1], "r");
    char cr;
    size_t lines = 0;

    if (ac != 2) {
        printf("%s\n", "you need to do ./executable instruction.txt");
        return 84;
    }
    while( cr != EOF ) { // compte le nombr de lignes, parcours jusqu'à EOF (fin du .txt), puis à chaque \n, incrémente
        if ( cr == '\n' ) {
            lines++;
        }
        cr = getc(fp);
    }
    lines++;
    rewind(fp);
    char *data[lines];
    int n;

    for (size_t i = 0; i < lines; i++) {
        data[i] = NULL;
        size_t n = 0;
        getline(&data[i], &n, fp);
    }
    init(sys);
    algorithm(data, lines, sys);
    fclose(fp);
    return 0;
}
