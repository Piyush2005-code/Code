#include<iostream>

using namespace std;


class Heap{
    private:
    int N;
    int *arr;
    int n = 0;

    public:
    Heap(int capacity): n(0), N(capacity){
        arr = new int[capacity];
    }

    void heapify(int i){
        if(!(i < n)) return;

        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < n && arr[left] < arr[smallest]){
            smallest = left;
        }
        if(right < n && arr[right] < arr[smallest]){
            smallest = right;
        }
        if(smallest != i){
            int temp = arr[smallest];
            arr[smallest] = arr[i];
            arr[i] = temp;
        }
        heapify(smallest);
    }

    void insert(int x){
        if(n == N){
            cout<< "Overflow Error";
            return;
        }
        int i = n;
        arr[n++] = x;
        while(i != 0){
            if(arr[i] < arr[(i - 1)/2]){ // to maintain the min Heap property, we have to bubble the smaller element up.
                int temp = arr[i];
                arr[i] = arr[(i - 1)/2];
                arr[(i - 1)/2] = temp;
            }
            i = (i - 1)/2;
        }
    }

    int peek(){return arr[0];}

    void remove_at_index(int i){
        if(i >= n){
            cout<< "Out of bounds Error\n";
            return;
        }
        arr[i] = arr[--n];
        heapify(i);
    }

    void printHeap(){
        int i = 0;
        while(i < n){
            cout<< arr[i]<< " ";
            i++;
        }
        cout<< "\n";
    }

};



int main(){

    int n;
    cin>> n;

    Heap heap(100);

    for(int i = 0; i < n; i++){
        int x;
        cin>> x;
        heap.insert(x);
    }

    heap.printHeap();
    heap.remove_at_index(0);
    heap.printHeap();

}