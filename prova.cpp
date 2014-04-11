#include <iostream>
#include <list>
#include <fstream> 

using namespace std;

// ###############################################################################################################
    

// dimensione per la creazione dell' array
int link, from, to;
int* generali;
int* aggiunti;
int** a;
int genIter=0;
void takeSon(int , int );
int n = 100000;

// ###############################################################################################################


// This class represents a directed graph using adjacency list representation
class Graph{
    int V;    // numero di vertici
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // costruttore
    void addEdge(int v, int w); // funzione che aggiunge collegamenti al grafo
    bool isReachable(int s, int d);  // ritorna true se c'è un cammino tra s e d
};

// creo il grafo
Graph g(n);
 
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w){
    adj[v].push_back(w); // Add w to v’s list.
}

// BFS controlla se d è raggiungibile da s
bool Graph::isReachable(int s, int d){
    // Base case
    if (s == d)
      return true;
 
    // segna tutti i vertici come non visitati
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // crea la coda per la BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // it will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while (!queue.empty()){

        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i){

            // If this adjacent node is the destination node, then return true
            if (*i == d)
                return true;
 
            // Else, continue to do BFS
            if (!visited[*i]){

                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
 
    return false;
}
// ###############################################################################################################


int main(int argc, char *argv[]){

    // apro il file input in lettura
    ifstream in ("input15.txt");
    in >> n >> link;

    generali = new int[n];
    aggiunti = new int[n];
    
    a = new int*[n];
    for (int ar = 0; ar < n; ar++){
        a[ar] = new int[n];
    }


    // inizializzo array di aggiunti tutto a 0
    for(int i=0;i<n;i++){
        aggiunti[i] = 0;
    }


    // inizializzazione matrice collegamenti tutta a 0
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            a[row][col] = 0;
        }
    }


    // aggiungo 1 ai collegamenti e aggiungo archi al grafo
    while(!in.eof()){
        in >> from >> to;
        a[from][to] = 1;
        g.addEdge(from, to);
    }

    /*
    // controllo se da un nodo u riesco ad arrivare a tutti gli altri nodi presenti nel grafo!
    for(int pk=0;pk<n;pk++){
	    int u = 2;

		    if(g.isReachable(u, pk))
		        cout<< "There is a path from " << u << " to " << pk << endl;
		    else
		        cout<< "There is no path from " << u << " to " << pk << endl;

	}
    */

    // itero su tutti i nodi del grafo
    for(int i=0;i<n;i++){
        // controllo se il nodo che prendo in considerazione è già stato aggiunto, se 0 aggiungo a generali
        if(aggiunti[i] == 0){
            generali[genIter] = i;
            genIter++;
            takeSon(0,i);
        }
    }


    ofstream outf;
    outf.open("output.txt");
    outf << genIter << endl;
    for(int gi=0;gi<genIter;gi++){
        if(aggiunti[generali[gi]] == 0){
            outf << generali[gi] << " "; 
        }
    }
    outf << endl;

    outf.close();
}



// ###############################################################################################################

void takeSon(int k, int i){
    for(int k=0;k<n;k++){
        // se trovo figlio nella matrice, ovvero arco da i a k
        if(a[i][k] == 1){
            // se il figlio non appartiene agli aggiunti
            if(aggiunti[k] == 0){
                // legge due, ovvero se il nodo figlio non raggiunge il padre
                if(!g.isReachable(k, i)){
                    aggiunti[k] = 1;
                    cout << i << " -> " << k << endl;
                    takeSon(0,k);
                }
            }
        }
    }
}