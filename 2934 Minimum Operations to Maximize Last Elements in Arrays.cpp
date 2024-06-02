#include <bits/stdc++.h>
using namespace std;

template <typename T>
class MyPair
{
public:
    T first;
    T second;

    MyPair(const T &f, const T &s) : first(f), second(s) {}

    static MyPair<T> minmax(const T &a, const T &b)
    {
        return MyPair<T>(min(a, b), max(a, b));
    }

    bool operator>(const MyPair<T> &other) const
    {
        return (first > other.first) || (second > other.second);
    }
};

class Solution
{
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        const auto pr_back = MyPair<int>::minmax(nums1.back(), nums2.back());
        int cntNSW = 0, cntSW = 0;

        auto a = nums1.begin(), end = nums1.end();
        auto b = nums2.begin();

        for (a; a != end; ++a, ++b)
        {
            const auto pr_i = MyPair<int>::minmax(*a, *b);
            if (pr_i > pr_back)
                return -1;

            if (*a > nums1.back() || *b > nums2.back())
                ++cntNSW;
            if (*a > nums2.back() || *b > nums1.back())
                ++cntSW;
        }

        return min(cntNSW, cntSW);
    }
};