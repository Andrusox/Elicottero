#include <iostream>
#include <list>
#include <fstream> 
#include <vector>
using namespace std;

// ###############################################################################################################

struct Graph{
    int V;
    list<int> *adj;
};    
int link, from, to,n;
int* aggiunti;
int* vicini;
int* presi;
int** matrix;
int max = 0;
int indicemax = 0;
int level = 1;
Graph* g;

// ###############################################################################################################

void init(int V){
    g = new Graph;
    g->V = V;
    g->adj = new list<int>[V];
}

void addEdge(int v, int w){
    g->adj[v].push_back(w);
}

list<int> returnList(int i){
    return g->adj[i];
}


// ###############################################################################################################


int main(int argc, char *argv[]){

    // apro il file input in lettura
    ifstream in ("input solito.txt");
    in >> n >> link;

    // inizializzo la struct Graph
    init(n);

    // allocazione dinamica degli array
    presi = new int[n];
    vicini = new int[n];
    psichici = new int[n];
    levels = new int[n];
    matrix = new int [n][];

    // metto tutto l'array a 0
    for(int i=0;i<n;i++){
        vicini[i] = 0;
        presi[i] = 0;
        psichici[i] = 0;
        levels[i] = 0;
    }


    // aggiungo archi al grafo
    while(!in.eof()){
        in >> from >> to;
        addEdge(from, to);
        addEdge(to,from);
    }

    in.close();                                               

    
    // creo un array con il numero dei vicini
    for(int i=0;i<n;i++){
        vicini[i] = returnList(i).size();
    }

    // piglio il più grande nodo, ovvero quello che ha più collegamenti
    for(int i=0;i<n;i++){
        if(vicini[i]>max){
            max = vicini[i];
            indicemax = i;
        }
    }

    
    matrix[level][k] = indicemax;

    list<int> lst = returnList(i);
    for(list<int>::iterator it=lst.begin(); it != lst.end(); ++it){
        int node = *it;
        matrix[level++][k++]
    }

    // apro il file in scrittura
    ofstream outf;
    outf.open("output.txt");

    // itero su tutti i nodi del grafo
    for(int i=0;i<n;i++){
        outf << "Vicini di " << i << ": " << vicini[i] << endl;
    }

    outf.close();
}

// ###############################################################################################################
