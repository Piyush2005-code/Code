/*
A bank has a simple policy for warning clients about possible fraudulent account activity. If the amount spent by a client on a particular day is greater than or equal to 2x the client's median spending for a trailing number of days, they send the client a notification about potential fraud. The bank doesn't send the client any notifications until they have at least that trailing number of prior days' transaction data.

Given the number of trailing days d and a client's total daily expenditures for a period of n days, determine the number of times the client will receive a notification over all n days.

Example
expenditure = [10,20,30,40,50]
d = 3

On the first three days, they just collect spending data. On day 4, trailing expenditures are [10,20,30]. The median is 20 and the day's expenditure is 40. Because 40 >= 2*20, there will be a notice. The next day, trailing expenditures are [20,30,40] and the expenditures are 50. This is less than 2*30 so no notice will be sent. Over the period, there was one notice sent.

Note: The median of a list of numbers can be found by first sorting the numbers ascending. If there is an odd number of values, the middle one is picked. If there is an even number of values, the median is then defined to be the average of the two middle values.

Complete the function activityNotifications in the code in order to return the total number of notices sent.

Input Format

The first line contains two space-separated integers n and d, the number of days of transaction data, and the number of trailing days' data used to calculate median spending respectively. The second line contains n space-separated non-negative integers where each integer i denotes expenditure[i].

Sample Input

9 5
2 3 4 2 3 6 8 4 5

Sample Output

2
*/

//Solution:

#include <iostream>
using namespace std;

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

int activityNotifications(int expenditure[], int d) {

}

int main() {
    int d, n;
    cin >> n;
    cin >> d;
    
    int expenditure[n];
    for (int i = 0; i < n; i++) {
        cin >> expenditure[i]
    }
    
    int result = activityNotifications(expenditure, d);

    cout << result << endl;

    return 0;
}
