#include <stdio.h>
#include <math.h>

float operate(float num1, char operation, float num2){

    float result;

    if(operation == '+'){
        result = num1 + num2;
    }

    if(operation == '-'){
        result = num1 - num2;
    }

    if(operation == '*' || operation == 't'){
        result = num1 * num2;
    }

    if(operation == '/'){
        result = num1 / num2;
    }

    if(operation == '^'){
        result = pow(num1, num2);
    }

    return result;
}
