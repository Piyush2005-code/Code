/*
In the kingdom of Numeria there was a legendary contest called the Tournament of Digits. Each participant received a scroll inscribed with digits forming a very large number. Along with the scroll they were also given a number k that told them how many digits they had to erase.

The rule of the contest was strict. After erasing exactly k digits the number that remained on the scroll had to be the smallest possible number that could be formed. The sages of Numeria also declared that the answer should never begin with leading zeroes because such numbers were considered improper unless the number itself became zero.

One skilled scribe was given the scroll 1432219 and asked to remove three digits. By carefully choosing to erase the digits four three and two she was left with 1219 which was indeed the smallest number possible.

Another challenger was handed the scroll 10200 and told to erase one digit. He decided to remove the digit one at the front which left 0200. The sages cleansed the leading zero and the result was 200.

Finally a young novice was given the short scroll 10 and asked to erase two digits. With nothing left on the scroll the only possible answer was zero.

Thus the Tournament of Digits became a test of patience strategy and wisdom where the art of erasing determined who could uncover the smallest number hidden within the scroll.
*/

//Solution:
#include <iostream>
#include <string>
#include <stack>
#include <algorithm> // For std::reverse

// Template class to handle the removal of k digits
class KDigitsRemover {
public:
    // Constructor to initialize the number and the count of digits to remove
    KDigitsRemover(const std::string& number, int removeCount)
        : num(number), k(removeCount) {}

    // Public method to perform the removal of k digits
    std::string removeKdigits() {
        
    }

private:
    std::string num; // Number as a string
    int k;           // Number of digits to remove
};

int main() {
    std::string num;
    int k;

    // Input handling
    std::cin >> num;
    std::cin >> k;

    // Create an instance of KDigitsRemover
    KDigitsRemover remover(num, k);

    // Call the method to get the smallest number
    std::string smallestNumber = remover.removeKdigits();

    // Output the result
    std::cout << smallestNumber << std::endl;

    return 0;
}