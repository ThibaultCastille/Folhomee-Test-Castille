/*
** FOLHOMEE PROJECT, 2021
** Folhomee
** File description:
** ex_01
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ITER atoi(av[1])

int main(int ac, char **av) {
    unsigned int result = 0;

    if (ac != 2) {
        printf("%s\n", "put a positive number in your first argument");
        return 84;
    }
    for (int i = 0; i != MAX_ITER; i++) {
        if (i % 3 == 0 || i % 5 == 0)
            result = result + i;
    }
    printf("%d\n", result);
}
