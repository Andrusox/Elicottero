#include <iostream>
#include <fstream>

using namespace std;

int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1, link;

void bfs(int v){

    for(i=1;i<=n;i++){
        cout << a[v][i] << endl;
        if(a[v][i] && !visited[i])
           q[++r] = i;
        if(f<=r){
          visited[q[f]] = 1;
          bfs(q[f++]);
         }
    }
}


int main(int argc, char *argv[]){

    int v, from, to;
    ifstream in ("input.txt");

    in >> n >> link;

    // inizializzazione
    for(i=1;i<=n;i++){
        q[i] = 0;
        visited[i] = 0;
    }

    // inizializzazione matrice collegamenti tutta a 0
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            a[row][col] = 0;
        }
    }



    while(!in.eof()){
        in >> from >> to;
        a[from][to] = 1;
    }

    cout << endl;
    cout << "------------------------------" << endl;
    cout << "   0 1 2 3 4 5 6 ..." << endl;
    for(int row=0;row<n;row++){
        cout << row << " |";
        for(int col=0;col<n;col++){
            cout << a[row][col] << " " ;
        }
        cout << endl;
    }
    cout << "------------------------------" << endl;


    // inserimento del vertice di partenza
    cout << "Enter the starting vertex:" << endl;
    cin >> v;
    bfs(v);

     // stampa i vertici che sono raggiungibili partendo da quel vertice
    cout << "The node which are reachable are:" << endl;
    for(i=0;i<n;i++){
        if(visited[i]){
            cout << i << " - possible!" << endl;
        }else{
           cout << i << " - Bfs is not possible" << endl;
        }
    }
}