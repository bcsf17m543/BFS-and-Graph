//#include <iostream>
//#include <string>
//#include <list>
//#include<iterator>
//#include <queue>
//using namespace std;
//
//class Node
//{
//public:
//	string color;
//	int distance;
//	int pred;
//	int id;
//	list<int> adj;
//	Node(int v)
//	{
//		color = "white";
//		distance = 0;
//		pred = 0;
//		id = v;
//	}
//	void insertAdj(int adjt)
//	{
//		adj.push_back(adjt);
//	}
//	void show()
//	{
//		cout << "ID:         " << id << endl;
//		cout << "Color:      " << color << endl;
//		cout << "Distance:   " << distance << endl;
//		cout << "Predecessor:" << pred << endl;
//	}
//};
//
//class Graph
//{
//public:
//
//	int vertex;
//	list<Node>* ver;
//
//	Graph(int v)
//	{
//		vertex = v;
//		ver = new list<Node>[v];
//	}
//	void insert(Node n)
//	{
//		ver->push_back(n);
//	}
//	void BFS(int s)
//	{
//		list<Node> ::iterator it;
//		for (it = ver->begin(); it != ver->end(); it++)
//		{
//			if (it->id == s)
//				break;
//		}
//		it->color = "gray";
//		queue<Node> q;
//		q.push(*it);
//		while (!q.empty())
//		{
//			Node tmp = q.front();
//			q.pop();
//
//			list<int>::iterator itt;
//			for (itt = tmp.adj.begin(); itt != tmp.adj.end(); itt++)
//			{
//
//				for (it = ver->begin(); it != ver->end(); it++)
//				{
//					if (it->id == *itt)
//						break;
//				}
//				if (it->color == "white")
//				{
//					it->color = "gray";
//					it->distance = tmp.distance + 1;
//					it->pred = tmp.id;
//					q.push(*it);
//				}
//			}
//			tmp.color = "black";
//			cout << "-----------------------------------------------------------------------------------\n";
//			tmp.show();
//			cout << "-----------------------------------------------------------------------------------\n";
//		}
//		return;
//	}
//	void show()
//	{
//		list<Node> ::iterator it;
//		for (it = ver->begin(); it != ver->end(); it++)
//		{
//			cout << "-----------------------------------------------------------------------------------\n";
//			it->show();
//			cout << "-----------------------------------------------------------------------------------\n";
//		}
//	}
//	//---------------------------------------------------TASK-2----------------------------------------------------
//	// no. of connected nodes function
//	int noOfConNodes()
//	{
//		int count = 0;
//		list<Node> ::iterator it;
//		for (it = ver->begin(); it != ver->end(); it++)
//		{
//			if (it->adj.size() != 0)
//				count++;
//		}
//		return count;
//	}
//
//};
//int main()
//{
//	cout << "Hello world";
//	/*Node n1(1);
//	n1.insertAdj(2);
//	n1.insertAdj(3);
//	Node n2(2);
//	n2.insertAdj(1);
//	n2.insertAdj(4);
//	Node n3(3);
//	n3.insertAdj(1);
//	n3.insertAdj(4);
//	Node n4(4);
//	n4.insertAdj(2);
//	n4.insertAdj(3);
//	Node n5(5);
//
//	Graph g(5);
//	g.insert(n1);
//	g.insert(n2);
//	g.insert(n3);
//	g.insert(n4);
//	g.insert(n5);
//	cout << "-----------------------------------------TASK-1------------------------------------------------\n";
//	g.BFS(2);
//	cout << "\n-----------------------------------------TASK-2------------------------------------------------\n";
//	cout << "Count of connected nodes:\t" << g.noOfConNodes() << endl;
//	*/cout << "-----------------------------------------------------------------------------------\n";
//	return 0;
//}