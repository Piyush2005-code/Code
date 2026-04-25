#include<iostream>
#include<vector>


using namespace std;


void mergesort(vector<int> &nums, int l, int r);

void merge(vector<int> &nums, int l, int m, int r);

void merge(vector<int> &nums, int l, int m, int r){

    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> left_nums(n1);
    vector<int> right_nums(n2);

    for(int i = 0; i < n1; i++)
        left_nums[i] = nums[l + i];
    for(int j = 0; j < n2; j++)
        right_nums[j] = nums[m + 1 + j];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2){
        if(left_nums[i] <= right_nums[j]){
            nums[k] = left_nums[i];
            i++; k++;
        }
        else{
            nums[k] = right_nums[j];
            j++; k++;
        }
    }
    // for the remaining elements, think why didn't we just put (i < n1 || j < n2) in the upper while loop?
    while(i < n1){
        nums[k] = left_nums[i];
        i++; k++;
    }

    while(j < n2){
        nums[k] = right_nums[j];
        j++; k++;
    }
}

void mergesort(vector<int> &nums, int l, int r){

    if(l < r){
        int m = (l + r)/2;
        mergesort(nums, l, m);
        mergesort(nums, m + 1, r);

        merge(nums, l, m, r);

    }
}

int main(){

    int size;
    
    cin>> size;

    vector<int> arr;

    for(int i = 0; i < size; i++){
        int x;
        cin>> x;
        arr.push_back(x);
    }

    mergesort(arr, 0, size - 1);

    for(int x: arr)
        cout<< x<< " ";
    cout<< "\n";
}