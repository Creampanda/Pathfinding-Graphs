#include "Graph.h"
#define DEBUG



int Node::idGenerator_ = 0;

int main() 
{

	Graph graph(4);
	graph.makeGrid();

	graph.showGraph();
	graph.BFS(3, 8);

	return 0;
}
