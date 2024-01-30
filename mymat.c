// to remember:
// make dynamic programing by so:
// take the original matrix - A0
// create matrix A1.
// compute: A1[i,j] = min(A0[i,j] , A0[i,1] + A0[1,j])
// and so on...
// overall function: A_K[i,j] = min (A_K-1[i,j] , A_K-1[i,k] + A_K-1[k,j])  

void FloydWarshall(int graph[][10]){
    int dist[10][10];

    //Initilize the solution matrix with the graph input
    for(int i = 0 ; i < 10; i++){
        for(int j = 0 ; j < 10 ; j++){
            dist[i][j] = graph[i][j];
        }
    }

    //update solution matrix 
    for(int k = 0 ;k<10 ;k++){
        for (int i = 0; i<10; i++) {
            for(int j = 0; j<10;j++){
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        
        }
    }
}