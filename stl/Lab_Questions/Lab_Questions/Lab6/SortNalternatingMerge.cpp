/*
Given two lists, write functions to sort one in ascending order and the other in descending order and then merge two sorted lists in an alternating fashion (start with the first list), until one list is depleted, at which point print the remaining elements of the other list.

Inputs: 
7
5 6 7 2 9 4 3
9
3 7 1 4 2 9 8 1 5

Outcome: 2 9 3 8 4 7 5 5 6 4 7 3 9 2 1 1 

Explanation: Sorting the lists in ascending and descending order gives:
1st list: 2 3 4 5 6 7 9
2nd list: 9 8 7 5 4 3 2 1 1 
Alternatingly printing the members gives 2 9 3 8 4 7 5 5 6 4 7 3 9 2, at which point the first list gets depleted, so you just continue printing the remaining of the 2nd list, which are 1 1.
*/

//Solution:

#include <iostream>
#include <vector>

using namespace std;

class ArrayOperations {
private:
    vector<int> *arr1, *arr2;

public:
    // Constructor to initialize arrays
    ArrayOperations(vector<int> &a1, vector<int> &a2) {
        arr1 = &a1;
        arr2 = &a2;
    }

    // Function to merge the arrays alternately and print the result
    void SortNalternatingMerge() {
        
    }
};

int main() {
    int n1, n2;

    // Reading the size and elements of the first array
    cin >> n1;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    // Reading the size and elements of the second array
    cin >> n2;
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    // Creating an object of ArrayOperations
    ArrayOperations arrayOps(arr1, arr2);

    // Sorting and Merging and printing the arrays
    arrayOps.SortNalternatingMerge();

    return 0;
}

//Solution:
/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ArrayOperations {
private:
    vector<int> *arr1, *arr2;

public:
    ArrayOperations(vector<int> &a1, vector<int> &a2) {
        arr1 = &a1;
        arr2 = &a2;
    }

    void SortNalternatingMerge() {
        sort(arr1->begin(), arr1->end());
        sort(arr2->begin(), arr2->end(), greater<int>());

        int i = 0, j = 0;
        int n1 = arr1->size(), n2 = arr2->size();

        while (i < n1 && j < n2) {
            cout << (*arr1)[i++] << " " << (*arr2)[j++] << " ";
        }

        while (i < n1) {
            cout << (*arr1)[i++] << " ";
        }

        while (j < n2) {
            cout << (*arr2)[j++] << " ";
        }

        cout << endl;
    }
};

int main() {
    int n1, n2;

    cin >> n1;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cin >> n2;
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    ArrayOperations arrayOps(arr1, arr2);
    arrayOps.SortNalternatingMerge();

    return 0;
}

*/