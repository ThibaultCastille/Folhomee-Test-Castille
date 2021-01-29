#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct sys_s {
    int nord;
    int sud;
    int est;
    int ouest;
    char direction;
    int i;
} sys_t;

void algorithm(char **stock, int size, sys_t *sys);
void check_position(char **stock, int numbers, sys_t *sys);
void check_rotation(char **stock, int numbers, sys_t *sys);