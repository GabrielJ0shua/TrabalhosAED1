#include "tad.h"
#include <stdlib.h>
#include <string.h>

struct soldado{
    char nome_do_soldado[20];
    struct soldado *next;
};