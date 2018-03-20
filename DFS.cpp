#include<iostream>
#include<list>
using namespace std;

class Graph{
	int vertices;
	list<int> *edges;
public:
	void addEdge(int source, int destination);
	void DFS(int source);
	void DFSUtil(int source, int *visited);
	Graph(int vertex);
};
Graph::Graph(int vertex){
	vertices = vertex;
	edges = new list<int>[vertex];
}

void Graph::addEdge(int source, int destination){
	edges[source].push_back(destination);
	return;
}
void Graph::DFS(int source){
	int *visited = new int[vertices];
	for (int index=0; index < vertices; index++){
		visited[index] = false;
	}
	DFSUtil(source, visited);
}

void Graph::DFSUtil(int source, int *visited){
	list<int>::iterator i;
	
	visited[source] = true;
	cout<<source;
	
	/*iterate thrugh the adjacent list*/
	for (i=edges[source].begin(); i != edges[source].end(); i++){
		if (!visited[*i]){
			DFSUtil(*i, visited);
		}
	}
	return;
}
int main()
{
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
    g.DFS(2);
 
    return 0;
}

