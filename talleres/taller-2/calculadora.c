
#define NUM1 100
#define NUM2 19

#include <stdio.h>
#include "biblioteca.h"

int main()
{

    int num1, num2;
    
    num1 = NUM1, num2 = NUM2;
    printf("Sean los números %d y %d:\n", num1, num2);

    printf("Suma: %d\n", lib_suma(num1, num2));
    printf("Resta: %d\n", lib_resta(num1, num2));
    printf("Multiplicacion: %d\n", lib_multiplicacion(num1, num2));
    printf("Division: %d\n", lib_division(num1, num2));
    printf("Raiz cuadrada de %d: %f\n", num1, lib_raiz_cuadrada(num1));
    printf("Raiz cuadrada de %d: %f\n", num2, lib_raiz_cuadrada(num2));

    return 0;
}
