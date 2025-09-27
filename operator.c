#include <stdio.h>
#include <math.h>

float operate(float num1, char operation, float num2){

  float result;

  if(operation == '+'){
    result = num1 + num2;
    printf("%f\n", result);
  }

  if(operation == '-'){
    result = num1 - num2;
    printf("%f\n", result);
  }

  if(operation == '*' || operation == 't'){
    result = num1 * num2;
    printf("%f\n", result);
  }

  if(operation == '/'){
    if(num2 == 0) {
      printf("DIVIDE BY 0 ERROR\n");
    } else {
      result = num1 / num2;
      printf("%f\n", result);
    }
  }

//  if(operation == '^'){
//    result = pow(num1, num2);
//    printf("%f\n", result);
//  }

  return result;
}
