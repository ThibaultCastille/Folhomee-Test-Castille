/*
** FOLHOMEE PROJECT, 2021
** Folhomee
** File description:
** ex_02
*/

#include <stdlib.h>
#include <stdio.h>

#define MAX_VALUE 4000000

void main() {
    int first = 1;
    int second = 1;
    int result = 0;
    int temp = 0;

    while (second <= MAX_VALUE) {
        temp = first + second;
        if (temp % 2 == 0)
            result = result + temp;
        first = second;
        second = temp;
    }
    printf("%d\n", result);
}
