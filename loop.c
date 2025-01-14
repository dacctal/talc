#include <stdlib.h>
#include <stdio.h>
#include "operator.c"
#include "giveOptions.c"

void loop(){
  char option;
  while(option != 'q'){
    int num1;
    int num2;
    char operation;

    system("clear");
    printf("Equation (ex. 1 + 2): ");
    scanf("%d %c %d", &num1, &operation, &num2);

    int result = operate(num1, operation, num2);
    printf("%d\n", result);

    giveOptions();
    scanf(" %c", &option);
    if(option == 'q'){
      break;
    }
    if(option == 'r'){
      continue;
    }
    if(option == 'u'){
      while(option != 'q'){
        system("clear");
        num1 = result;
        printf("Equation (ex. + 2): ");
        scanf(" %c %d", &operation, &num2);

        result = operate(num1, operation, num2);
        printf("%d\n", result);

        giveOptions();
        scanf(" %c", &option);
        if(option == 'q'){
          break;
        }
        if(option == 'r'){
          break;
        }
        if(option == 'u'){
          continue;
        }
      }
    }
  }
  system("clear");
}
