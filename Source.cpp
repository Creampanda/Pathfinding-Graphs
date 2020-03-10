#include "Graph.h"
#define DEBUG



int Node::idGenerator_ = 0;

int main() 
{

	Graph graph(5);
	graph.makeGrid();

	graph.showGraph();
	graph.disableNode(5);
	graph.disableNode(11);
	graph.disableNode(17);
	graph.disableNode(18);
	graph.disableNode(8);
	graph.disableNode(9);
	graph.disableNode(2);

	graph.BFS(10, 4);

	return 0;
}