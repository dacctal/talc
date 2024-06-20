#include <stdio.h>
#include <math.h>

int operate(int num1, char operation, int num2){
    int result;
    if(operation == '+'){
        result = num1 + num2;
    }
    if(operation == '-'){
        result = num1 - num2;
    }
    if(operation == '*'){
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
