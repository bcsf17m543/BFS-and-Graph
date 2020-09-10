#include<vector>
#include<queue>
#include<iterator>
#include<iostream>

using namespace std;
enum color{white,grey,black};
class Node
{
public:
	color clr;
	int elem;
	int dist;
	Node* pred;
	vector<Node>adj;
	Node()
	{
		clr = white;
		elem = 0;
		dist = -1;
		pred = NULL;
	}
	Node(int k)
	{
		clr = white;
		elem = k;
		dist = -1;
		pred = NULL;
	}
	friend ostream& operator<<(ostream &out, Node &c);

	void show()
	{
		for (int it = 0; it != adj.size(); ++it)
		{
			cout << adj[it].elem << "\n ";
			//cout << adj[it].pred << "\n ";
			//cout << adj[it].clr << "\n ";
			cout << "-----------\n";

		}
		cout << endl;

	}
	bool operator==(Node& n)
	{
		if (n.elem == this->elem && n.clr == this->clr&&n.dist == this->dist&&n.pred == this->pred)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Work(Node &k)
	{
		for (int i = 0; i < k.adj.size(); i++)
		{
			if (k.adj[i].clr == white)
			{
				k.adj[i].clr = grey;
				k.adj[i].dist = adj[i].dist + 1;
				k.adj[i].pred = &k;
			}
		}
	}
	void Enqueue(queue<Node> &q, Node& j)
	{
		for (int i = 0; i < adj.size(); i++)
		{
			q.push(adj[i]);
		}
    }
	void setc(color k)
	{
		clr = k;
    }
};
 ostream& operator<<(ostream &out, Node &c)
{
	 out <<"Element"<< c.elem << " \n";
	 out << "Predecessor" << c.pred << " \n";
	 out << "Color" << c.clr << " \n";


	return out;
}
class Graph
{
private:
	Node* list;
	int size;
	int count;
public:
	int getsize()
	{
		return size;
	}
	Node getind(int i)
	{
		return list[i];
	}
	Graph(int k)
	{
		size = k;
		list = new Node[size];
		initialize();
	}
	void initialize()
	{
		for (int i = 0; i < size; i++)
		{
			list[i].elem = i;
		}
	}
	void Addvertex(int src, int dest)
	{
		Node k(dest);
		Node j(src);
		list[src].adj.push_back(k);
		list[dest].adj.push_back(j);

	}
	void Display()
	{
		for (int i = 0; i < size; i++)
		{
			/*cout << list[i].elem << " ";
			 list[i].show();*/
			cout << list[i];
		}
	}
	Node getNode(Node &n)
	{
		if (Search(n))
		{
			for (int i = 0; i < size; i++)
			{

				if (list[i] == n)
				{
					return list[i];
				}
			}
		}
	}
	bool Search(Node &n)
	{
		bool k = false;
		for (int i = 0; i < size; i++)
		{
			if (list[i] == n)
			{
				k = true;
			}
		}
		return k;
	}
	int count_connection()
	{
		int count = 0;
		for(int i = 0; i < size; i++)
		{
			count += list[i].adj.size();
		}
		return count/2;
	}
	//try
	void ADDVER(int src, int dest)
	{
		Node k(src);
		list[dest].adj.push_back(k);

	}
	void Reverse()
	{
		Node* temp = new Node[size];
		int j = 0;
		for (int i = size; i > 0; i++)
		{
			temp[i] = list[j];
			j++;
		}
	}
	bool AllBlack()
	{
		bool k = false;
		for (int i = 0;i < size; i++)
		{
			if (list[i].clr == black)
			{
				k = true;
			}
			else
			{
				k = false;
			}
		}
		return k;
	}
	void setNode(Node k,int i)
	{
		list[i] = k;
	}
	
};

void BFS(Graph &g, Node &n)
{
	for (int i = 0; i < g.getsize(); i++)
	{
		Node temp = g.getind(i);
		temp.clr = white;
		temp.dist = -1;
		temp.pred = NULL;
	
	Node t2 = g.getind(i);
	t2.clr = grey;
	t2.dist = 0;
	t2.pred = NULL;
	queue<Node>q;
	q.push(t2);
	while (!q.empty())
	{
		Node t3 = q.front();
		q.pop();
		for (int j = 0; j< t3.adj.size(); j++)
		{
			if (t3.adj[j].clr == white)
			{
				t3.adj[j].setc(grey);
				t3.adj[j].dist = t3.dist + 1;
				t3.adj[j].pred = &t3;
				q.push(t3.adj[j]);
			}
		}
		t3.setc(black);
		t3.show();

	}
}
	
}
int time;
void DFS_visit(Graph &g, Node &t)
{
	time = time + 1;
	t.dist = time;
	t.clr = grey;
	bool check = false;
	for (int j = 0; j < t.adj.size(); j++)
	{
		cout << "Edge(" << t.elem << "," << t.adj[j].elem << ")";

				if (t.adj[j].clr == white)
				{
					cout << " : tree edge\n";
					check = true;
					t.adj[j].pred = &t;
					DFS_visit(g, t.adj[j]);
				}
				if (check == true)
				{
					if (t.adj[j].clr == grey)
					{
						cout << " : back edge\n";
					}
					if (t.adj[j].clr == black)
					{
						if (t.adj[j].dist > t.dist)
						{
							cout << " : forward edge\n";

						}
						else
						{
							cout << " : cross edge\n";
						}
					}
				}
			

	
	}
	t.clr = black;
	time = time + 1;
	t.dist = time;
	cout << t.elem;



}

void DFS(Graph &g)
{
	for (int i = 0; i < g.getsize(); i++)
	{
		Node temp = g.getind(i);
		temp.clr = white;
		temp.pred = NULL;
	}
	time = 0;
	for (int i = 0; i < g.getsize(); i++)
	{
		Node temp2 = g.getind(i);

		if (temp2.clr ==white)
		{
			DFS_visit(g,temp2);
			cout << " ";
		}

	}
	

}
bool Reverse(Graph &g)
{
	Graph jonk(5);
	jonk.ADDVER(1, 0);
	jonk.ADDVER(2, 1);
	jonk.ADDVER(4, 2);
	jonk.ADDVER(2, 4);
	jonk.ADDVER(3, 2);
	jonk.ADDVER(0, 3);
	DFS(jonk);
	if (jonk.AllBlack())
	{
		return true;
	}
	else
	{
		return false;
	}

}
bool Check(Graph&k)
{
	DFS(k);
	if (k.AllBlack())
	{
		return true;
	}
	else
	{
		return true;
	}
}
int main()
{
	Graph g(7);
	Node k(5);
	g.ADDVER(1, 2);
	g.ADDVER(2, 4);
	g.ADDVER(4, 5);
	g.ADDVER(5, 6);
	g.ADDVER(2, 3);
	DFS(g);
//	g.Display();
	//------------>task2 lab11<-------------
	Graph jon(5);
	Node wk(2);
	cout << endl;
	jon.ADDVER(0, 1);
	jon.ADDVER(1, 2);
	jon.ADDVER(2, 4);
	jon.ADDVER(4, 3);
	jon.ADDVER(3, 2);
	jon.ADDVER(3, 0);

	BFS(jon,wk);
	//cout << endl;
	//cout << "Before reverse:"<<Check(jon)<<endl;
	////reverse
	//
	//cout << "After reverse: " << Reverse(jon) << endl;


	//g.Display();
	//cout << "------------";
	//BFS(g, k);
	////------------TASK 2 -----------//
	//Task4

	//cout << "\nNumber of connected vertices: " << g.count_connection() << endl;
	return 0;
}