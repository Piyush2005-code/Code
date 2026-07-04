#include<iostream>
#include<vector>
#include<queue>


using namespace std;

// With this it becomes a min heap...means the rightmost element is the 
struct compare{
    bool operator()(int a, int b){
        return a > b;
    }
};


int main(){

    priority_queue<int, vector<int>, compare> pq;
    int n;
    cin >> n;
    int x;

    for(int i = 0; i < n; i++){
        cin >> x;
        pq.push(x);
    }

    for(int i = 0; i < n; i++){
        cout << pq.top();
        pq.pop();
    }

}
