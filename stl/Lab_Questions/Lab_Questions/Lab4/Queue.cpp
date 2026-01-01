/*
Write a C++ program to perform basic operations on a queue. The program should include functions for enqueueing, dequeueing, checking the front element, determining if the queue is full, and checking if the queue is empty. The queue should be capable of holding up to 100 integers.

The program must take an input of n number of integers and enqueue them into the queue. After the enqueueing process, the program should execute the following operations in the specified order and print their outputs:

front(): Print the element at the front of the queue.
dequeue(): Remove and print the element at the front of the queue.
printWholeQueue(): This function should empty the queue and print all the elements in the order they were dequeued.
isFull(): Print 1 if the queue is full, otherwise 0.
isEmpty(): Print 1 if the queue is empty, otherwise 0.
Input Format:

The first line of input should be the number of elements, N.
The second line should contain N integers, separated by spaces.
Output Format:

Output the result of front() on a new line.
Output the result of dequeue() on a new line.
Output the elements in the queue, emptied by printWholeQueue(), on a new line.
Output 1 or 0 for isFull() on a new line.
Output 1 or 0 for isEmpty() on a new line.
Example:

Input:
5
15 123 62 10 44
Output:
15
15
123 62 10 44 
0 
1 
*/

//Solution:
#include <iostream>
#define MAX 100;
using namespace std;

// Queue structure
class Queue {
private:
    int items[MAX];
    int front, rear;

public:
    // Constructor to initialize the queue
    Queue() {
        // TODO: Initialize front and rear
    }

    // Check if the queue is full
    bool isFull() {
        // TODO: Return true if the queue is full, false otherwise
    }

    // Check if the queue is empty
    bool isEmpty() {
        // TODO: Return true if the queue is empty, false otherwise
    }

    // Enqueue an element
    void enqueue(int value) {
        // TODO: Add an element to the queue if it is not full
    }

    // Dequeue an element
    int dequeue() {
        // TODO: Remove and return the front element of the queue if it is not empty
    }

    // Get the front element
    int getFront() {
        // TODO: Return the front element of the queue
    }

    // Print and empty the entire queue
    void printWholeQueue() {
        // TODO: Dequeue all elements and print them
    }
};

int main() {
    Queue q;

    int n;
    cin >> n;
    int value;

    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }

    // TODO: Print the front element using getFront()
    // TODO: Dequeue and print an element using dequeue()
    // TODO: Print and empty the whole queue using printWholeQueue()
    // TODO: Print if the queue is full using isFull()
    // TODO: Print if the queue is empty using isEmpty()

    return 0;
}