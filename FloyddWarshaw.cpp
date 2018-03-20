/*Vikash Kumar FloyddWarshaw Algorithm Get the shortest distance from one node to another in Graph*/
/*Graph implemented in Adjaceny Matrix Directed Graph*/
#include<iostream>
#define V 5
#define UNDEFINED 99999
using namespace std;

void DisplaySolutionGraph(int graph[V][V]){
	int index_r = 0;
	int index_c = 0;
	for (index_r=0; index_r < V; index_r++){
		for (index_c=0; index_c< V; index_c++){
			if (graph[index_r][index_c] == UNDEFINED){
				cout<<index_r<<","<<index_c<<" :: "<<"INFINITE"<<"\n";
			}
			else
			{
				cout<<index_r<<","<<index_c<<" :: "<<graph[index_r][index_c]<<"\n";
			}
		}
	}
	return;
	
}
void ShortestPath(int graph[V][V], int Row, int Col){
	int sol[V][V];
	int i,j,k;
	
	/*Init solution matrix with the graph input*/
	/*No intermediate vertex has been taken*/
	for (i=0; i< Row; i++){
		for (j=0; j < Col; j++){
			sol[i][j] = graph[i][j];
		}
	}
	
	for(k=0; k<V; k++){
		for(i=0;i<V;i++){
			for(j=0;j<V;j++){
				if (sol[i][k] + sol[k][j] < sol[i][j]){
					sol[i][j] = sol[i][k] + sol[k][j];
				}
			}
		}
	}
	
	DisplaySolutionGraph(sol);
	return;
}
int main(){
	int graph[V][V] = {{0, 10, UNDEFINED, 30, 40},
					   {UNDEFINED , 0, UNDEFINED, UNDEFINED, 30},
					   {UNDEFINED , UNDEFINED, 0, UNDEFINED, 20},
				       {UNDEFINED, UNDEFINED, UNDEFINED, 0, UNDEFINED},
					   {UNDEFINED, UNDEFINED, 11, UNDEFINED, 0},
					  };
	ShortestPath(graph, 5 ,5);
	return 0;
}
