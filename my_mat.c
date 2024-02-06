#include "my_mat.h"

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