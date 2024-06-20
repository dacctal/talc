#include <stdlib.h>
#include <stdio.h>
#include "operator.c"

void loop(){
    int num1;
    int num2;
    char operation;

    printf("Equation (ex. 1 + 2): ");
    scanf("%d %c %d", &num1, &operation, &num2);

    int result = operate(num1, operation, num2);
    printf("%d\n", result);
}
