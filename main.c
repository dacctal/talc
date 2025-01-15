#include <stdio.h>
#include "operator.c"

int main(int argc, char *argv[]) {
  float num1;
  float num2;
  char operation;

  if(argc < 0) {
    printf("Usage: %s 1 + 1", argv[0]);
    return 1;
  }

  //  int i;
  //  for( i = 1; i < sizeof(argv[0]) - 1; i++ ) {
  //    printf("%s \n", argv[i]);
  //  }

  sscanf(argv[1], "%f", &num1);
  sscanf(argv[2], "%c", &operation);
  sscanf(argv[3], "%f", &num2);

  //  printf("equasion:\n");
  //  printf("%d\n", num1);
  //  printf("%c\n", operation);
  //  printf("%d\n", num2);

  float result = operate(num1, operation, num2);
  printf("%f\n", result);

  return 0;

}
