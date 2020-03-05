#include "Graph.h"

//Getting our grid size [N*N]
Graph::Graph(size_t rows) : rows_(rows), vertices_(rows* rows)
{
	for (size_t i = 0; i < rows * rows; i++)
	{
		Node a;
		nodeVector_.push_back(a);
	}
}

void Graph::addNode(Node& someNode) 
{
	nodeVector_.push_back(someNode);
}

void Graph::showGraph() 
{
	for (auto x : nodeVector_) x.showNode();
}

Node& Graph::getNode(const int i) { return nodeVector_[i]; }

void Graph::connectNodes(int src, int dest)
{
	nodeVector_[src].adjustNode(nodeVector_[dest]);
}

//Creating grid by connectin vertices (like matrix N*N)
void Graph::makeGrid()
{
	for (size_t i = 0; i < rows_; ++i)
	{
		for (size_t j = rows_ * i; j < rows_ * (i + 1) - 1; ++j)
		{
			connectNodes(j, j + 1);
		}
	}
	for (size_t i = 0; i < rows_; ++i)
	{
		for (size_t j = i; j < rows_ * (rows_ - 1) + i; j += rows_)
		{
			connectNodes(j, j + rows_);
		}
	}
}


// breadth-first search
void Graph::BFS(int startingNode, int targetNode)
{
	//Bool array for visited vertices
	bool* visited = new bool[vertices_];
	for (size_t i = 0; i < vertices_; i++)
	{
		visited[i] = false;
	}

	list<int> queue;
	visited[startingNode] = true;
	queue.push_back(startingNode);

	//While there are still not visited vertices in the graph
	while (!queue.empty())
	{
		int current = queue.front();
		queue.pop_front();

		//Getting current vertex adjacent list
		list<int> currentNodeAdjList = nodeVector_.at(current).getAdjList();
		cout << "Checking adj list for vertex " << current << endl;
		for (auto i = currentNodeAdjList.begin(); i!= currentNodeAdjList.end(); ++i )
		{
			if (*i == targetNode)
			{
				cout << "We found target Node!! It's connected with " << current << endl;
				return;
			}
			if (!visited[*i])
			{
				cout << "Visit and enqueue " << *i << endl;
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}
