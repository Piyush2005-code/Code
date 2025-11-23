#include<iostream>
#include<queue>

using namespace std;

struct elem{
	int a;
};

struct comp{
	bool operator()(const elem& v1, const elem& v2) const{
		return v1.a > v2.a;
	}
};

int main(){

	priority_queue<elem, vector<elem>, comp> pq; // greater<int> simply means that the values from the left of the priority queue gets progressively greater and greater when moving towards the right.

	int n;
	cin>> n;
	for(int i = 1; i < n + 1; i++){
	int x; cin>> x;
	pq.push({x});
	}

	for(int i = 0; i < n; i++){
	cout<< pq.top().a<< " ";
	pq.pop();
	}

}
