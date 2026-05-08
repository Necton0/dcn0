#include <iostream>
using namespace std;

class LinkStateRouting{
  public:
  int n;
  int INT_MAX = 999;
  int adjMatrix[10][10];
  
  LinkStateRouting(int node){
    n = node;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(i==j) adjMatrix[i][j] = 0;
        else adjMatrix[i][j] = INT_MAX;
      }
    }
  }
  
  void addEdge(int u, int v, int weight){
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
  }
  
  void printAdjMatrix(){
    cout<<"ADJ MATRIX: \n";
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(adjMatrix[i][j] == INT_MAX){
          cout<<"INF\t";
        }
        else{
          cout<<adjMatrix[i][j]<<"\t";
        }
      }
      cout<<endl;
    }
  }
  
  void dijkstra(){
   int dist[10], visited[10], start, min, next;
   cout<<"Enter the start node";
   cin>>start;
   
   for(int i=0; i<n; i++){
      dist[i] = adjMatrix[start][i];
      visited[i] = 0;
   }
   visited[start] = 1;
   dist[start] = 0;
   
   for(int i=0; i<n-1; i++){
      min = INT_MAX;
      for(int j=0; j<n; j++){
        if(visited[j]==0 && dist[j]<min){
          min = dist[j];
          next = j;
        }
      }
      
      visited[next] = 1;
      for(int j=0; j<n; j++){
        if(visited[j]==0 && dist[next] + adjMatrix[next][j] < dist[j]){
          dist[j] = dist[next] + adjMatrix[next][j];
        }
      }
   }
   
   cout<<"\nShorted nodes: ";
   for(int i=0; i<n; i++){
      cout<<"Node "<<i<<": "<<dist[i]<<"\n";
   }
   
  }
  
};

int main(){
  int n, e;
  cout<<"Enter the number of n: ";
  cin>>n;
  LinkStateRouting lsr(n);
  cout<<"Enter the number of edges: ";
  cin>>e;
  
  int u, v, weight;
  for(int i=0; i<e; i++){
    cout<<"Enter (u, v, weight) for edge "<<i+1<<": ";
    cin>>u>>v>>weight;
    lsr.addEdge(u, v, weight);
  }
  
  lsr.printAdjMatrix();
  lsr.dijkstra();
  
  return 0;
}
