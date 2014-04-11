#include <iostream>
#include <fstream>

using namespace std;

int a[20][20],visited[20],n,i,j;


int main(int argc, char *argv[]){

    int v, from, to, link;
    ifstream in ("input.txt");

    in >> n >> link;

    // inizializzazione
    for(i=0;i<n;i++){
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
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            cout << a[row][col] << " " ;
        }
        cout << endl;
    }
    cout << "------------------------------" << endl;


    // inserimento del vertice di partenza
    cout << "Enter the starting vertex:" << endl;
    cin >> v;

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