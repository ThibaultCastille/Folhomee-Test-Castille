/*
** FOLHOMEE PROJECT, 2021
** deplacement
** File description:
** ex03
*/

#include "include/ex03.h"

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
