#define N 10
#define bagSize 5
#define maxWeight 20

void FloydWarshall(int graph[][N], int m);
void insertMatrix(int arr[][N]);
int hasPath(int arr[][N],int i ,int j);
int knapSack(int weights[], int values[], int selected_bool[]);
int max(int a, int b);
void getSelectedItems(char items[bagSize], int selected_bool[bagSize], char result[bagSize]);
void printItems(char arr[bagSize]);

