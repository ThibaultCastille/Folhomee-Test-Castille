#include "ex03.h"

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

void check_rotation(char **stock, int numbers, sys_t *sys) { // fonction qui gère la rotation
    if (stock[sys->i][0] == 'R') {
        int turn = 0;
        int save = 0;
        char test[10] = {'E','S','W','N','E','S','W','N'};

        for (; numbers != 0; numbers = numbers - 90)
            turn++;
        for (int w = 0; w < strlen(test); w++) {
            if (test[w] == sys->direction) {
                save = w;
                break;
            }
        }
        sys->direction = test[save + turn];
    }
    else if (stock[sys->i][0] == 'L') {
        int turn = 0;
        int save = 0;
        char test[10] = {'E','N','W','S','E','N','W','S'};
        for (; numbers != 0; numbers = numbers - 90)
            turn++;
        for (int w = 0; w < strlen(test); w++) {
            if (test[w] == sys->direction) {
                save = w;
                break;
            }
        }
        sys->direction = test[save + turn];
    }
}

void check_position(char **stock, int numbers, sys_t *sys) { // fonction qui gère la position
    switch(stock[sys->i][0]) {
        case 'N' :
            sys->nord = sys->nord + numbers;
            break;
        case 'S' :
            sys->sud = sys->sud + numbers;
            break;
        case 'E' :
            sys->est = sys->est + numbers;
            break;
        case 'W' :
            sys->ouest = sys->ouest + numbers;
            break;
        case 'F' :
            if (sys->direction == 'N')
                sys->nord = sys->nord + numbers;
            if (sys->direction == 'S')
                sys->sud = sys->sud + numbers;
            if (sys->direction == 'E')
                sys->est = sys->est + numbers;
            if (sys->direction == 'W')
                sys->ouest = sys->ouest + numbers;
                break;
        }
}

void algorithm(char **stock, int size, sys_t *sys) {
    for (sys->i = 0; sys->i != size; sys->i++) {
        int numbers = extract_numbers(stock[sys->i]);
        check_position(stock, numbers,sys);
        check_rotation(stock, numbers, sys);
    }
    int estwest = 0;
    int nordsud = 0;

    if (sys->nord >= sys->sud) {
        nordsud = sys->nord - sys->sud;
        sys->sud = 0;
    }
    if (sys->sud > sys->nord) {
        nordsud = sys->sud - sys->nord;
        sys->nord = 0;
    }
    if (sys->est >= sys->ouest) {
        estwest = sys->est - sys->ouest;
        sys->ouest = 0;
    }
    if (sys->ouest > sys->est) {
        estwest = sys->ouest - sys->est;
        sys->est = 0;
    }
    printf("%s", "position : ");
    printf("%d\n", estwest + nordsud);

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
