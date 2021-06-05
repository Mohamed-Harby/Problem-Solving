// Problem statement: https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
#define all(v) begin(v), end(v)

class Solution {
private:
    const int fib[45] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584,
                         4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229,
                         832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817,
                         39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 1134903170};  // fibonacci series in range 1~1e9 + (the fib number which comes after 1e9)to aid in binary search 
public:
    int findMinFibonacciNumbers(int k) {
        int cnt = 0;
        while (k) {
            auto temp = lower_bound(all(fib), k);
            if (*temp == k) {
                cnt++;
                break;
            } else {
                temp--;
                k -= *temp;
                cnt++;
            }
        }
        return cnt;
    }
};
// Proof
/*
 * Assume x, y, .... are fitting well in solution -> x+y, ... will fit in a less number of factors.
 * if x+y is the remaining value and they are not contiguous values in fibonacci series
 * and by using my approach we will get these values in two steps.
 *
 * */
