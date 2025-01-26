#include <stdio.h>
#include "operator.c"
#include "data.c"

int main(int argc, char *argv[]) {
  float num1;
  float num2;
  char operation;

  if(argc == 1) {
    printf(
      "\n \t talc \n \t The single-operation terminal calculator \n\n \t Usage:\t%s 1 + 1 \n\n\n",
      argv[0]);
    return 1;
  }



  //  int i;
  //  for( i = 1; i < sizeof(argv[0]) - 1; i++ ) {
  //    printf("%s \n", argv[i]);
  //  }



  if(argc == 2) {
    char option;
    sscanf(argv[1], "%c", &option);
    if(option == 'l') {
      readFile();
    }
  } else {
    sscanf(argv[1], "%f", &num1);
    sscanf(argv[2], "%c", &operation);
    sscanf(argv[3], "%f", &num2);



    //  printf("equation:\n");
    //  printf("%d\n", num1);
    //  printf("%c\n", operation);
    //  printf("%d\n", num2);



    float result = operate(num1, operation, num2);

    writeFile(num1, operation, num2, result);

  }

  return 0;

}
