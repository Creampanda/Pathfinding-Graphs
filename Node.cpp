#include "Node.h"

// Connect current node with other
void Node::adjustNode(Node& someNode)
{
	// Cheack if they already connected
	if (find(this->adjList_.begin(), this->adjList_.end(), someNode.getId()) == adjList_.end())
	{
		//adding Nodes to each others adjacent list
		this->adjList_.push_back(someNode.getId());
		someNode.adjList_.push_back(this->getId());
		adjList_.sort();	
	}
}

void Node::showNode()
{
	cout << "Node number " << this->id_ << " connected with: [ ";
	for (auto x : adjList_)
	{
		cout << x << " ";
	}
	cout << "]" << endl;

}

list<int> Node::getAdjList() {return adjList_;}

int Node::getId() { return id_; };