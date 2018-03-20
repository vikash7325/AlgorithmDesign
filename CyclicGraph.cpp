#include<iostream>
#include<list>
#include<limits.h>

using namespace std;
class Graph{
	int vertices;
	list<int> *edges;
	bool isCyclicVisited(int v, bool visited[], bool *rs);
public:
	Graph(int vertices);
	void addEdge(int v, int w);
	bool isCyclic();  /*return true if there is a cycle in the graph*/
};

Graph::Graph(int v){
	this->vertices = v;
	edges = new list<int>[v];
}

void Graph::addEdge(int v, int w){
	edges[v].push_back(w);           /* Add w to the v's list */
}
bool Graph::isCyclicVisited(int v, bool visited[], bool *recStack){
	if (false == visited[v]){
		/* Mark the current node as visited */
		visited[v] = true;
		recStack[v] = true;
		
		list<int>::iterator i;
		for (i=edges[v].begin(); i != edges[v].end(); i++){
			if (!visited[*i] && isCyclicVisited(*i, visited, recStack)){
				return true;
			}
			else if (recStack[*i]){
				return true;
			}
		}
	}
	return false;
}
bool Graph::isCyclic(){
	/* Mark all the vertices that are not visited */
	bool *visited = new bool[vertices];
	bool *recStack = new bool[vertices];
	for (int i=0; i < vertices;i++)
	{
		visited[i] = false;
		recStack[i] = false;
	}
	
	/* Call the recursive helper function to detect the cycle in different DFS tree */
	for (int i=0; i < vertices; i++){
		if (isCyclicVisited(i, visited, recStack)){
			return true;
		}
	}
	return false;
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
	
	if (g.isCyclic())
	{
		cout<<"Cyclic";
	}
	else
	{
		cout<<"Not Cyclic";
	}
	
	return 0;
}
