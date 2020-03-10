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
	nodeVector_.at(startingNode).setStep(0);
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
				nodeVector_.at(*i).setStep(nodeVector_.at(current).getStep() + 1);
				cout << "Can get here by " << nodeVector_.at(*i).getStep() << " steps!" << endl;
				list<int> path = this->pathfinding(startingNode, targetNode);
				this->showpath(path);
				return;
			}
			if (!visited[*i])
			{
				// Setting how many step it takes to get to that node
				nodeVector_.at(*i).setStep(nodeVector_.at(current).getStep() + 1);
				cout << "Amount steps to " << nodeVector_.at(*i).getId() << " : " << nodeVector_.at(*i).getStep() << endl;
				cout << "Visit and enqueue " << *i << endl;
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	cout << "Sorry! Can't find a path to node!" << endl;

}

list<int> Graph::pathfinding(int startingNode, int targetNode)
{
	int currentNode = targetNode;
	list<int> path;
	while (nodeVector_.at(currentNode).getStep() != 0)
	{
		list<int> currentNodeAdjList = nodeVector_.at(currentNode).getAdjList();
		
		int nextstep;
		for (auto i = currentNodeAdjList.begin(); i != currentNodeAdjList.end(); ++i)
		{
			if (nodeVector_.at(*i).getStep() >= 0)
			{
				nextstep = *i;
				break;
			}
		}
		for (auto i = currentNodeAdjList.begin(); i != currentNodeAdjList.end(); ++i)
		{
			if (nodeVector_.at(*i).getStep() >= 0)
			{
				if (nodeVector_.at(*i).getStep() < nodeVector_.at(nextstep).getStep())
				{
					nextstep = *i;
				}
			}

		}

		currentNode = nextstep;
		path.push_front(nextstep);
	}

	path.push_back(targetNode);

	return path;
}

void Graph::showpath(list<int> path)
{
	auto i = path.begin();
	cout << *(i++);
	while (i != path.end())
	{
		cout << " -> " << *i++;
	}

	cout << endl;
}

void Graph::disableNode(int nodeId)
{
	for (auto i = nodeVector_.at(nodeId).getAdjListRef().begin(); i != nodeVector_.at(nodeId).getAdjListRef().end(); i++)
	{
		nodeVector_.at(*i).getAdjListRef().remove(nodeId);
	}

	nodeVector_.at(nodeId).getAdjListRef().clear();
}
