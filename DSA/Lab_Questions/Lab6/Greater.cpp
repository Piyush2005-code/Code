/*
Given a linked list, return an array greater[] where every ith element of greater contains the node value of the linked list which is strictly greater than the ith node (1 indexed). If a greater node is not available, it is set to 0.

Example, given following list input : [2, 7, 4, 3, 5]
Returns : [7, 0, 5, 5, 0]
*/

//Solution:


#include <iostream>
#include <vector>
using namespace std;

// Node class for the linked list
class Node {
public:
    int data;
    Node* next;
};

// LinkedList class for the main linked list operations
class LinkedList {
private:
    Node* head;

public:

    // Function to calculate the greater array
    vector<int> calculateGreater(int size) { }

    // Function to print the linked list
    void printList() {}
};

int main() {
    int size;
    cin >> size;

    LinkedList list;

    // Input the elements of the linked list
    for (int i = 0; i < size; i++) {
        int data;
        cin >> data;
        list.append(data);
    }

    // Calculate the greater array
    vector<int> greater = list.calculateGreater(size);

    // Output the greater array
    for (int i = 0; i < size; i++) {
        cout << greater[i] << " ";
    }
    cout << endl;

    return 0;
}