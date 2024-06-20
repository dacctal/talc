#include <stdlib.h>
#include <stdio.h>
#include "operator.c"

void loop(){
    char option;
    while(option != 'q'){
        int num1;
        int num2;
        char operation;

        printf("Equation (ex. 1 + 2): ");
        scanf("%d %c %d", &num1, &operation, &num2);

        int result = operate(num1, operation, num2);
        printf("%d\n", result);

        printf("Enter \"q\" to exit\n");
        printf("Enter \"r\" to start over\n");
        printf("Enter \"u\" to use result in next talc\n");
        printf("Option: ");
        scanf(" %c", &option);
        if(option == 'q'){
            break;
        }
        if(option == 'r'){
            continue;
        }
        if(option == 'u'){
            while(option != 'q'){
                num1 = result;
                printf("Equation (ex. + 2): ");
                scanf(" %c %d", &operation, &num2);

                result = operate(num1, operation, num2);
                printf("%d\n", result);

                printf("Enter \"q\" to exit\n");
                printf("Enter \"r\" to start over\n");
                printf("Enter \"u\" to use result in next talc\n");
                printf("Option: ");
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
}
