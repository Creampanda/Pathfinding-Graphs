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
public:

	Node() { id_ = idGenerator_++; };

	// Connect current node with other
	void adjustNode(Node& someNode);
	
	//Show current node with all connections
	void showNode();

	
	list<int> getAdjList();

	int getId();

};