#include "data.c"
#include "operator.c"
#include <stdio.h>

int main(int argc, char *argv[]) {
  float num1;
  float num2;
  char operation;

  if (argc == 1) {
    printf("\n \t talc \n \t The single-operation terminal calculator \n\n \t "
           "Usage:\t%s 1 + 1 \n\n\n",
           argv[0]);
    return 1;
  }

  if (argc == 2) {
    char option;
    sscanf(argv[1], "%c", &option);
    if (option == 'l') {
      readFile();
    }
  } else {
    sscanf(argv[1], "%f", &num1);
    sscanf(argv[2], "%c", &operation);
    sscanf(argv[3], "%f", &num2);

    float result = operate(num1, operation, num2);

    writeFile(num1, operation, num2, result);
  }

  return 0;
}
