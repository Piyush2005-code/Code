// For an equation of a line in 2D, ax + by+c =0, a, b, and c are given. Find the perpendicular distance of a point (x,y) from the line and print the distance.
// Input Format: First Line represents the value of a,b, and c respectively. The next line contains the respective values of x, and y.
// Output Format: Print the value representing the distance.

// Sample Input:
// 4 -3 -5
// -1 3

// Sample Output:
// 3.6


#include<stdio.h>
#include<math.h>

double absolute(double x){
    return (x > 0)? x: -x;
}

int main(){

    int a, b, c, x, y;
    scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
    double dist = absolute(a * x + b * y + 1.0 * c) / sqrt(a * a * 1.0 + b * b * 1.0);
    printf("%f", dist);

}

// Solution is working.