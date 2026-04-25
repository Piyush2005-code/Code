/*
Implement a program in C++ to process an array (of up to 32 elements) by reversing every alternate group of 3 consecutive digits, while parsing from left to right. The program should repeatedly loop back to the beginning of the array upon reaching the end, but this looping should be limited to 20 repetitions in total. The array should be of variable length (up to 32 elements) and the elements should be input by the user.

Input:
User provides the number of elements (up to 32) and then enters the elements of the array. For example, for an 8-size array, the user might input: 3 4 5 6 1 5 7 8.

Output:
The program outputs a series where every alternate group of three elements is reversed. The entire series repeats a maximum of 20 times. For the given example input, the output would be: 5 4 3 5 1 6 3 8 7 6 5 4 … (continuing in this pattern for a total of 20 repetitions).
*/

//Solution:

#include <iostream>
#include <vector>
using namespace std;

class ArrayProcessor {
private:
    int *arr; // Vector to hold the array elements
    int n;           // Number of elements in the array
    const int MAX_ITERATIONS = 20; // Maximum number of iterations

public:
    // Constructor to initialize the array size and elements
    ArrayProcessor(int size) {
        n = size;
        arr = new int[n];    
    }

    // Function to input the elements of the array from the user
    void inputArray() {

    }

    // Function to print reversed or original groups of 3 elements
    void printReversedGroups() {

    }
};

int main() {
    int n;

    // Ask the user for the number of elements in the array

    cin >> n;

    // Create an instance of ArrayProcessor
    ArrayProcessor processor(n);

    // Input the array elements
    processor.inputArray();

    // Print the reversed groups
    processor.printReversedGroups();

    return 0;
}