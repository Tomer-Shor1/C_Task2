#include <stdio.h>

int main(){
    int i,j;
    char choice;
    printf("A - function1 \n");
    printf("B - function 2\n");
    printf("C - function 3\n");
    printf("D - exit");

    
    do {
    scanf("d" , &choice);
    
    switch (choice) {
        case 'A':
            //scan matrix input..
            break;  
        case 'B':
            scanf("d" , &i);
            scanf("d" , &j);
            //if soulution matrix[i][j] != 0 -> return true
            break;
        case 'C':
            //return solution[i][j];
            break;
        case 'D':

        default:
            printf("invlaid input");  
    }
    
    }
    while (choice != 'D')

    return 0;
}