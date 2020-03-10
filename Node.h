#pragma once
#include <list>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Node
{
	//Unique vertex ID generator
	static int idGenerator_;
	//Vertex ID
	int id_;
	// Adjacent list for all connected vertexes
	list <int> adjList_;
	// Steps from starting node
	int steps_ = -1;
public:

	Node() { id_ = idGenerator_++; };

	// Connect current node with other
	void adjustNode(Node& someNode);
	
	//Show current node with all connections
	void showNode();

	void setStep(int step);
	int getStep();
	
	list<int> getAdjList();

	list<int> & getAdjListRef();

	int getId();

};