#include<stdio.h>
#include<limits.h>
#define V 7;
int A[7]]7] = {
  
    {0, 2, 4, 1, 0, 0, 0},
    {2, 0, 3, 0, 7, 0, 0},
    {4, 3, 0, 5, 8, 0, 0},
    {1, 0, 5, 0, 9, 6, 0},
    {0, 7, 8, 9, 0, 10, 12},
    {0, 0, 0, 6, 10, 0, 15},
    {0, 0, 0, 0, 12, 15, 0}
};
int visited[7] = {0};
void PrimeMst(){
  int parent[V];
  int key[V];
  int totalCost = 0;

for(int i =0;i<V;i++){
    key[i] = INT_MAX;
  }
  key[0] = 0;
  parent[0] =-1;


  for(int count =0;coutn<V-1;coutn++){
    int min = INT_MAX , u;
    for(int v = 0;v<V;v++){
      if(!visited[v] && key[v] < min){
        min = key[v];
        u = v;
      }
    }

      visited[u] = 1;
for(int  v =0;v<V;v++){
if(A[u][v]  && !visited[v] && A[u][v] <key[v]){
        parent[v] = u;
        key[v] = A[u][v];
      }
    }
  }

    printf("Minimum Spanning Tree Edges:\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d (Weight: %d)\n", parent[i], i, A[i][parent[i]]);
        totalCost += A[i][parent[i]];
    }
    printf("Total Cost of MST: %d\n", totalCost);
}

int main() {
    PrimMST();
    return 0;
}


}
