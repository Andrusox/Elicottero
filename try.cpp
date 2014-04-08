#include <iostream>

using namespace std;


int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;

void bfs(int v){

    for(i=1;i<=n;i++){
        if(a[v][i] && !visited[i])
           q[++r]=i;
        if(f<=r){
          visited[q[f]]=1;
          bfs(q[f++]);
         }
    }
}


int main(int argc, char *argv[]){

    int v;

    cout << "Enter the number of vertices:" << endl;
    cin >> n;

    // inizializzazione
    for(i=1;i<=n;i++){
        q[i]=0;
        visited[i]=0;
    }

    // creazione della matrice per i collegamenti
    cout <<"Enter graph data in matrix form:" << endl;
     for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
        cin >> a[i][j];

    // inserimento del veritce di partenza
     cout << "Enter the starting vertex:" << endl;
     cin >> v;
     bfs(v);

     // stampa i vertici che sono raggiungibili partendo da quel vertice
     cout << "The node which are reachable are:" << endl;
     for(i=1;i<=n;i++)
      if(visited[i])
       cout << i << endl;
      else
       cout << "Bfs is not possible" << endl;
}