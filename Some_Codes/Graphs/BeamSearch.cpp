#include<iostream>
#include<queue>
#include<vector>
#include<list>


using namespace std;


class graph{
	private:
	int n;
	vector<list<int>> adjlist;

	public:
	graph(int n){
		adjlist = vector<list<int>>(n, list<int>());
		this->n = n;
	}

	// Creating a Directed Graph...
	void addEdge(int x, int y){
		adjlist[x].push_back(y);
	}
	
	vector<int> beamSearch(int start, int k){
		vector<int> prev(this->n, -1);
		queue<int> q;
		vector<int> visited(this->n, 0);
		q.push(start);
		visited[start] = 1;

		while(!q.empty()){
			int element = q.front();
			q.pop();
			priority_queue<int, vector<int>> maxHeap;
			for(int x: adjlist[element]){
				if(!visited[x]) maxHeap.push(x);	
			}

			for(int i = 0; i < k; i++){
				if(!maxHeap.empty()){
					q.push(maxHeap.top());
					prev[maxHeap.top()] = element;
					visited[maxHeap.top()] = 1;
					maxHeap.pop();
				}	
			}
		}
		return prev;
	}

};



int main(){
	int n, m;
	cout<< "Enter the number of nodes: ";
	cin>> n;
	cout<< "\nEnter the number of edges: ";
	cin>> m;
	graph g(n);

	for(int i = 0; i < m; i++){
		int x, y;
		cout<< "\nEnter the first and the second element of the edge: ";
		cin>> x; cout<< " "; cin>> y;
		g.addEdge(x, y);
	}

	vector<int> parent_array = g.beamSearch(0, 3);

	for(int i = 0; i < n; i++)
		cout<< parent_array[i]<< " ";

}


