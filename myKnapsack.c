#include "stdio.h"
#include "my_mat.h"




int main(){
    int weights[bagSize];
    int values[bagSize];
    int selected_bool[bagSize];
    char items[20];
    char result[bagSize];
    
    //get inputs from the user
    for (int i = 0; i<bagSize; i++) {
        printf("Enter item's name: ");
        scanf("%s", items);

        printf("Enter weight: ");
        scanf("%d", &weights[i]);

        printf("Enter value: ");
        scanf("%d", &values[i]);
    }
    
    int value = knapSack( weights,  values,  selected_bool);
    getSelectedItems(items, selected_bool, result);
    printItems(result);


    return 0;
}