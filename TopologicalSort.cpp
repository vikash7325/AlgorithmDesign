#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph{
	int vertices;
	list<int> *edges;
	
public:
	Graph(int vertex);
	void TopologicalSort();
	void addEdge(int source, int destination);
	void TopologicalSortUtil(int vertex, bool *visitedOrNot, stack<int> &myStack);
};

Graph::Graph(int vertex){
	this->vertices = vertex;
	edges = new list<int>[vertex];
	return;
}

void Graph::addEdge(int source, int destination){
	edges[source].push_back(destination);
	return;
}

void Graph::TopologicalSortUtil(int vertex, bool *visitedOrNot, stack<int> &myStack){
	visitedOrNot[vertex] = true;
	
	list<int>::iterator i;
	for (i = edges[vertex].begin(); i != edges[vertex].end(); i++){
		if (!visitedOrNot[*i]){
			TopologicalSortUtil(*i, visitedOrNot, myStack);
		}
	}
	
	myStack.push(vertex);
	return;
}

void Graph::TopologicalSort(){
	bool *visited = new bool[vertices];
	stack<int> Stack;
	list<int>::iterator i;
	for (int index=0; index < vertices; index++){
		visited[index] = false;
	}
	
	for (int index=0; index < vertices; index++){
		if (false == visited[index]){
			TopologicalSortUtil(index, visited, Stack);
		}
	}
	
	while (false == Stack.empty()){
		cout<<Stack.top()<<" ";
		Stack.pop();
	}
	return;
}

int main(){
	Graph g(6);
	g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is a Topological Sort of the given graph \n";
    g.TopologicalSort();
	return 0;
}
