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
int* generali;
int* aggiunti;
int genIter=0;
void takeSon(int);
int numCon = 0;
vector<int> vectorLink;
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

bool isReachable(int s, int d){
    // Base case
    if (s == d){
      return true;
    }
 
    // segna tutti i vertici come non visitati
    bool *visited = new bool[g->V];
    for (int i = 0; i < g->V; i++)
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
        for (i = g->adj[s].begin(); i != g->adj[s].end(); ++i){

            // If this adjacent node is the destination node, then return true
            if (*i == d){
                delete [] visited;
                return true;
            }
 
            // Else, continue to do BFS
            if (!visited[*i]){

                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    delete [] visited;
    return false;
}

// ###############################################################################################################


int main(int argc, char *argv[]){

    // apro il file input in lettura
    ifstream in ("input solito.txt");
    in >> n >> link;

    // inizializzo la struct Graph
    init(n);

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
        addEdge(from, to);
    }
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
            takeSon(i);
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

    // stampo i collegamenti degli alberi finali
    for(int p=0;p<vectorLink.size();p+=2){
        outf << vectorLink[p] << " " << vectorLink[p+1] << endl; 
    }

    outf << endl;
    outf.close();
}

// ###############################################################################################################

void takeSon(int i){

    // mi prendo la lista 
    list<int> lst = returnList(i);
    // se la lista contiene almeno un elemento eseguo
    if(lst.size() > 0){
        for(list<int>::iterator it=lst.begin(); it != lst.end(); ++it){
            int node = *it;
            if(aggiunti[node] == 0){
                if(!isReachable(node,i)){
                    aggiunti[node] = 1;
                    vectorLink.push_back(i);
                    vectorLink.push_back(node);
                    takeSon(node);
                }
            }
        }
    }
}