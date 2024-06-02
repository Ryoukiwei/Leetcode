#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        int slow = n;
        int fast = squaredDigitSum(n);

        while (slow != fast)
            getNext(slow, fast);

        return slow == 1;
    }

private:
    int squaredDigitSum(int n)
    {
        int sum = 0;
        while (n)
        {
            int temp = n % 10;
            sum += temp * temp;
            n /= 10;
        }

        return sum;
    }

    void getNext(int &first, int &second)
    {
        first = squaredDigitSum(first);
        second = squaredDigitSum(squaredDigitSum(second));
    }
};