// In the city of Malorin, there is a grand Library of Keys. The library shelves are built like a B-tree: each floor of the library represents one level of the tree. The ground floor is the root (depth = 1). Every time a new key arrives, it is carefully placed into the library following B-tree rules.
// One day, a scholar comes and asks:“Tell me, how many keys are stored exactly on floor number D?”
// Your task: After inserting all keys into the B-tree of minimum degree t, count and print the number of keys present at depth D, that is,
// Given n keys and a B-tree of minimum degree t:
// Insert the keys in the given order into an initially empty B-tree.
// For a given depth D, count how many keys are located at that depth.
// Root is at depth 1.
// Depth increases as we move down the tree.
// Constraints:
// n = number of keys (0 <= n <= 1000)
// t = minimum degree (t >= 2)
// Hint: A node in a B-tree with minimum degree t holds at most 2t-1 keys and has at most 2t children.

// Sample Input:
// 7 3
// 10 20 5 6 12 30 7
// 2

// Output:
// 6

#include <iostream>
#include <vector>
#include <algorithm>
// Include other standard headers as needed, e.g., <cmath>, <string>, etc.

using namespace std;

// === BEGIN: STUDENT'S CODE AREA ===
// The student should implement their function/class/logic here.

/**
 * PROBLEM STATEMENT:
 * [Briefly restate the core task, e.g., "Given an array of integers, 
 * return the index of the first occurrence of the target value."]
 *
 * PARAMETERS:
 * @param arr: The input array of integers.
 * @param target: The value to search for.
 * @return: The index of the target, or -1 if not found.
 */
int findFirstOccurrence(const std::vector<int>& arr, int target) {
    // TODO: Implement the solution logic here.
    
    // Example placeholder:
    // for (size_t i = 0; i < arr.size(); ++i) {
    //     if (arr[i] == target) {
    //         return i;
    //     }
    // }
    // return -1;
    
    return -1; // Default return to satisfy function signature
}

// === END: STUDENT'S CODE AREA ===


// -----------------------------------------------------------------------------
// The Main Function and Testing Infrastructure (DO NOT MODIFY)
// -----------------------------------------------------------------------------
int main() {
    // Fast I/O (good practice)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read problem-specific input (e.g., array size, elements, target)
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> input_array(n);
    for (int i = 0; i < n; ++i) {
        cin >> input_array[i];
    }

    int target_value;
    if (!(cin >> target_value)) return 0;

    // Call the student's implemented function
    int result = findFirstOccurrence(input_array, target_value);

    // Print the result (must match the expected output format exactly)
    cout << result << "\n";

    return 0;
}