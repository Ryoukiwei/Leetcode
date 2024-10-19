class Solution
{
public:
    char findKthBit(int n, int k)
    {
        if (n == 1)
            return '0';

        const int len = (1 << n) - 1;
        const int mid = len / 2 + 1;

        if (k == mid)
            return '1';
        if (k < mid)
            return findKthBit(n - 1, k);
        return '1' - findKthBit(n - 1, len - k + 1) + '0';
    }
};