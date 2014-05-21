#include <iostream>
#include <list>
#include <fstream> 
#include <vector>

using namespace std;

// ###############################################################################################################
    
int link, from, to;
int* generali;
int* aggiunti;
int genIter=0;
void takeSon(int,int);
int n = 10000;
int numCon = 0;
vector<int> vectorLink;

// ###############################################################################################################


// This class represents a directed graph using adjacency list representation
class Graph{
    int V;    // numero di vertici
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // costruttore
    void addEdge(int v, int w); // funzione che aggiunge collegamenti al grafo
    void stampoQualcosa();
    int returnSize(int i);
    list<int> returnList(int i);
    bool isReachable(int s, int d);  // ritorna true se c'è un cammino tra s e d
};

// creo il grafo | PROBLEMA IL GRAFO VIENE CREATO CON n NODI PER n SETTATO INIZIALMENTE
Graph g(n);
 
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w){
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::stampoQualcosa(){

    list<int>::iterator bom;
    list<int> pippo = adj[0];
    for (bom=pippo.begin(); bom != pippo.end(); bom++){
        cout << *bom << endl;
    }
    cout << pippo.size() << endl;
}


int Graph::returnSize(int i){
    return adj[i].size();
}

list<int> Graph::returnList(int i){
    return adj[i];
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
    ifstream in ("input solito.txt");
    in >> n >> link;

    // allocazione dinamica degli array
    generali = new int[n];
    aggiunti = new int[n];

    // inizializzo array di aggiunti tutto a 0
    for(int i=0;i<n;i++){
        aggiunti[i] = 0;
    }

    // aggiungo 1 ai collegamenti e aggiungo archi al grafo
    while(!in.eof()){
        in >> from >> to;
        //a[from][to] = 1;
        g.addEdge(from, to);

    }

    g.stampoQualcosa();

    in.close();

    // apro il file in scrittura
    ofstream outf;
    outf.open("output.txt");

    // itero su tutti i nodi del grafo
    for(int i=0;i<n;i++){
        // controllo se il nodo che prendo in considerazione è già stato aggiunto, se 0 aggiungo a generali
        if(aggiunti[i] == 0){
            generali[genIter] = i;
            genIter++;
            takeSon(0,i);
        }
    }

    // uso per trovare il numero di consiglieri facendo il check con gli aggiunti
    for(int gi=0;gi<genIter;gi++){
        if(aggiunti[generali[gi]] == 0){
             numCon++;
        }
    }

    // stampo il numero dei generali
    outf << numCon << endl;

    // stampo i generali
    for(int gi=0;gi<genIter;gi++){
        if(aggiunti[generali[gi]] == 0){
            outf << generali[gi] << " "; 
        }
    }
     outf << endl;

    for(int p=0;p<vectorLink.size();p+=2){
        outf << vectorLink[p] << " " << vectorLink[p+1] << endl; 
    }

    outf << endl;
    outf.close();
}



// ###############################################################################################################

void takeSon(int k, int i){

    list <int> lst = g.returnList(i);
    list<int>::iterator it;

    if(g.returnSize(i) > 0){
       for (it=lst.begin(); it != lst.end(); ++it){
            // se il figlio non appartiene agli aggiunti
            if(aggiunti[*it] == 0){
                // legge due, ovvero se il nodo figlio non raggiunge il padre
                if(!g.isReachable(*it, i)){
                    aggiunti[*it] = 1;
                    //vectorLink.push_back(i);
                    //vectorLink.push_back(*it);
                    cout << i << " -> " << *it << endl;
                    takeSon(0,*it);
                }
            }
        }
    }
}