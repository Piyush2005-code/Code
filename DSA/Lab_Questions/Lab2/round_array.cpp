/*
7. This is new year and there is a special game being played at IITJ.                		
These are the ways how the game is played. 
1) There are say  ‘x’ students in the class. Each student is labeled from 1 (first student) to x (last student).
2) A paper is given to n-th student.
3) The next p-th student who gets the paper quits the game.
4) The paper is passed until there is one last student who hasn't left the game.
5) The student becomes the class leader.
Now, your task is to find the number of last student.

Input
The first line contains a number T (0 <= T <= 106).
Each of the next T lines contains 3 integers which are x (0 < x<= 103), n, p (0 < n, p <= x) and are separated by a single space.

Output
For each test case, print the required answer.

*/
#include <iostream>
#include <vector>
using namespace std;

class Game {
private:
    int x; // Number of students
    int n; // Initial student who gets the paper
    int p; // Steps to pass the paper

public:
    int id(i){
        return i - 1;
    }

    Game(int x, int n, int p) : x(x), n(n), p(p) {}

    int findwinner() {
        int arr[x];
        for(int i = 0; i < x; i++) arr[i] = i + 1;
        int sum = 0;
        while(su)

    }
};

int main() {
    int T;
    cin >> T; 

    while (T--) {
        int x, n, p;
        cin >> x >> n >> p;

    }

    return 0;
}