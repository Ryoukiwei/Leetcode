#include <vector>
#include <array>
#include <bitset>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool primeSubOperation(vector<int> &nums)
    {
        const int n = nums.size();
        const auto primes = generatePrimes();

        int prevNum = 0;
        for (int &num : nums)
        {
            auto it = lower_bound(primes.begin(), primes.end(), num - prevNum);
            if (it != primes.begin() && (num - *prev(it) > prevNum))
                num -= *prev(it);

            if (num <= prevNum)
                return false;

            prevNum = num;
        }

        return true;
    }

private:
    array<int, 168> generatePrimes()
    {
        const int kMax = 1000;
        array<int, 168> primes{};
        bitset<kMax> isPrime;
        isPrime.set();

        for (int i = 2, idx = 0; i < kMax; ++i)
        {
            if (isPrime[i])
            {
                primes[idx++] = i;
                for (int j = i * i; j < kMax; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        return primes;
    }
};
