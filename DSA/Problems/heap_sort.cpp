#include<iostream>
#include<string>

using namespace std;

template<typename T>
void swap(T& a, T& b){
	T temp = a;
	a = b;
	b = temp;
}

class HeapSort {
	private:
	vector<int> arr;
	int n;
	void heapSort(vector<int>& arr, int i){
		int n = arr.size();
		int largest = i;


	}

	public:
	HeapSort(int N){
	arr = vector<int>(N, -1);
	n = 0;	
	}

};


template<typename T>
void printVector(vector<T> arr){
	for(auto x: arr){
		cout<< x<< " ";
	}
	cout<< "\n";
}


int main(){

	vector<int> arr = {1, 3, 6, 8, 0, 2};

	swap(arr[0], arr[1]);

	

}
