#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#define DEBUG


using namespace std;


class Node
{
	static int idGenerator_;  // ���������� ��� ������ ������� ID
	int id_; // ID �������
	list <int> adjList_; //������ ���� ��������� � ������ �������� ������
public:

	Node() { id_ = idGenerator_++; } 

	// �������� ������� � ����
	void adjustNode(Node & someNode)
	{
		// ��������� �� ������� �� ��� ���
		if (find(this->adjList_.begin(), this->adjList_.end(), someNode.getId()) == adjList_.end())
		{
			this->adjList_.push_back(someNode.getId());
			someNode.adjList_.push_back(this->getId());
			adjList_.sort(); // ��������� ������		
		}
#ifdef DEBUG
		else
		{
			cerr << "This nodes : " << this->getId() << " and " << someNode.getId() << " already connected!" << endl;
		}

#endif // DEBUG

	}

	//������� ������� � ��������� � ��� ������ �������
	void showNode()
	{
		cout << "Node number " << this->id_ << " connected with: [ ";
		for (auto x : adjList_)
		{
			cout << x << " ";
		}
		cout << "]" << endl;

	}

	int getId() { return id_; }

};

int Node::idGenerator_ = 1;

class Graph
{   //���������� ������
	size_t vertices_ = 0;
	//������ �������� ��� ������� �����
	vector <Node> nodeVector_;  
public:

	Graph(size_t vertices) : vertices_(vertices)
	{
		for (size_t i = 0; i < vertices; i++)
		{
			Node a;
			nodeVector_.push_back(a);
		}
	}

	void addNode(Node & someNode) 
	{
		nodeVector_.push_back(someNode);
	}
	void showGraph()
	{
		for (auto x : nodeVector_) x.showNode();
	}

	Node& getNode(const int i) { return nodeVector_[i]; }

	//��������� �������
	void connectNodes(int src, int dest)
	{
		nodeVector_[src-1].adjustNode(nodeVector_[dest-1]);
	}
};



int main()
{

	Graph graph(5);
	graph.connectNodes(1, 2);
	graph.connectNodes(2, 3);
	graph.connectNodes(1, 4);

	graph.connectNodes(1, 5);
	graph.showGraph();


	return 0;
}