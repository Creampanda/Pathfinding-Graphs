#pragma once
#include "Node.h"

class Graph{
	size_t rows_ = 0;
	size_t vertices_ = 0;
	//Storing all vertices
	std::vector <Node> nodeVector_;
public:

	Graph(size_t rows);
	

	void addNode(Node& someNode);

	void showGraph();

	Node& getNode(const int i);

	void connectNodes(int src, int dest);

	void makeGrid();

	void BFS(int startingNode, int targetNode);

	list<int> pathfinding(int startingNide, int targetNode);
	void showpath(list<int> path);
	
	void disableNode(int node);

};


