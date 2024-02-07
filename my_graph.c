#include <stdio.h>
#include "my_mat.h"

int main(){
    int i,j;
    char choice;
    int arr[10][10]; 
    printf("A - function1 \n");
    printf("B - function 2\n");
    printf("C - function 3\n");
    printf("D - exit");

    
    do {
    scanf("%c", &choice);
    switch (choice) {
        case 'A':
            insertMatrix(arr);
            break;  
        case 'B':
            scanf("%d" , &i);
            scanf("%d" , &j);
            int asnwer = hasPath(arr, i ,j);
            printf("%d", asnwer);
            break;
        case 'C':
            //return solution[i][j];
            break;
        case 'D':

        default:
            printf("invlaid input");  
        }
    }
    while (choice != 'D');

    return 0;
}