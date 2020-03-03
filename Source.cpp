#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#define DEBUG


using namespace std;


class Node
{
	static int idGenerator_;  // Уникальный для каждый вершины ID
	int id_; // ID вершины
	list <int> adjList_; //Список всех связанных с данной вершиной вершин
public:

	Node() { id_ = idGenerator_++; } 

	// Добавить вершину в граф
	void adjustNode(Node & someNode)
	{
		// Проверяем не связаны ли они уже
		if (find(this->adjList_.begin(), this->adjList_.end(), someNode.getId()) == adjList_.end())
		{
			this->adjList_.push_back(someNode.getId());
			someNode.adjList_.push_back(this->getId());
			adjList_.sort(); // Сортируем список		
		}
#ifdef DEBUG
		else
		{
			cerr << "This nodes : " << this->getId() << " and " << someNode.getId() << " already connected!" << endl;
		}

#endif // DEBUG

	}

	//Вывести вершину и связанные с ней другие вершины
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

int Node::idGenerator_ = 0;

class Graph
{   //Количество вершин
	size_t rows_ = 0;
	size_t vertices_ = 0;
	//Вектор хранящий все вершины графа
	vector <Node> nodeVector_;  
public:

	Graph(size_t rows) : rows_(rows), vertices_(rows*rows)
	{
		for (size_t i = 0; i < rows * rows; i++)
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

	//Соединяем вершины
	void connectNodes(int src, int dest)
	{
		nodeVector_[src].adjustNode(nodeVector_[dest]);
	}

	//Делаем сетку 
	void makeGrid()
	{
		for (size_t i = 0; i < rows_; ++i)
		{
			for (size_t j = rows_*i; j < rows_*(i + 1) - 1; ++j)
			{
				connectNodes(j, j + 1);
			}
		}
		for (size_t i = 0; i < rows_; ++i)
		{
			for (size_t j = i; j < rows_ * (rows_ - 1) + i; j+= rows_)
			{
				connectNodes(j, j + rows_);
			}
		}
	}
};



int main()
{

	Graph graph(3);
	graph.makeGrid();

	graph.showGraph();


	return 0;
}