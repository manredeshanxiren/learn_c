#include <stdio.h>    

#include <stdlib.h>    

#include "calc.h"    

int main(int argc, char* argv[])

{

    int a = 1, b = 2;

    int c = add1(a, b);

    printf("%d %d %d\n", c, a, b);

    return EXIT_SUCCESS;

}