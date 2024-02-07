#include "my_mat.h"
#include "stdio.h"

// to remember:
// make dynamic programing by so:
// take the original matrix - A0
// create matrix A1.
// compute: A1[i,j] = min(A0[i,j] , A0[i,1] + A0[1,j])
// and so on...
// overall function: A_K[i,j] = min (A_K-1[i,j] , A_K-1[i,k] + A_K-1[k,j])  


void FloydWarshall(int graph[][N], int m){
    int dist[N][N];
    

    //Initilize the solution matrix with the graph input
    for(int i = 0 ; i < m; i++){
        for(int j = 0 ; j < m ; j++){
            dist[i][j] = graph[i][j];
        }
    }

    //update solution matrix 
    for(int k = 0 ;k<m ;k++){
        for (int i = 0; i<m; i++) {
            for(int j = 0; j<m;j++){
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}


void insertMatrix(int arr[][N]){

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j<N; j++)
        {
            scanf("%d" , &arr[i][j]);
        } 
    }
}

int hasPath(int arr[][N],int i ,int j){
    if (arr[i][j] != 0)
    {
       return arr[i][j];
    }
    else{
        return 0;
    }
}



int knapSack(int weights[], int values[], int selected_bool[]){
        int maximumWeight = maxWeight;
        int answer[bagSize][maxWeight];


        //find the values
        for(int i = 0; i<=bagSize; i++){
            for (int j = 0; j <=maximumWeight; j++) {
                if (i==0 || j == 0) {
                    answer[i][j] = 0;
                }
                else if (weights[i-1] <= j) {
                    answer[i][j] = max(values[i-1] + answer[i-1][maximumWeight-weights[i-1]], answer[i-1][j]);
                }
                else {
                    answer[i][j] = answer[i-1][j];
                }
            }
        }

        //update the selected_bool array
        int sz = maxWeight;
        for(int i = bagSize; i>0; i--){
            if (answer[i][sz-1] != answer[i-1][sz-1]) {
                selected_bool[i-1] = 1;    //--> flag 1 if item has selected
                sz = sz-weights[i-1];
            }
        }

        //return the maximal value
        return answer[bagSize-1][maxWeight-1];  
}


void getSelectedItems(char items[bagSize], int selected_bool[bagSize], char result[bagSize]){
    int result_index = 0;
    for(int i = 0; i<bagSize; i++){
        if (selected_bool[i] == 1) {
            result[result_index] = items[i];
            result_index++;
        }
    }
}

void printItems(char arr[bagSize]){
    printf("[");
    for (int i = 0; i<bagSize; i++) {
        printf("%c" , arr[i] );
        printf(",");
    }
    printf("]");
}

int max(int a , int b){
    return (a>b) ? a : b;
}