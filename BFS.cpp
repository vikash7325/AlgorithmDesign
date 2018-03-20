#include<iostream>
#include<list>
using namespace std;

class Graph{
	int vertices;
	list<int> *edges;
public:
	void addEdge(int source, int destination);
	void BFS(int source);
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

void Graph::BFS(int source){
	int *visited = new int[vertices];
	
	/* Initialize the visited index to false */
	for (int index=0; index < vertices; index++){
		visited[index] = false;
	}
	
	list<int> queue;
	list<int>::iterator i;
	visited[source] = true;
	queue.push_back(source);
	
	while(!queue.empty()){
		source = queue.front();
		cout<<source;
		queue.pop_front();
		/*iterate thrugh the adjacent list*/
		for (i=edges[source].begin(); i != edges[source].end(); i++){
			if (!visited[*i]){
				visited[*i] = true;
				queue.push_back(*i);
			}
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
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}

