#include <vector>
#include <algorithm>
using namespace std;

class CustomStack
{
public:
    CustomStack(int maxSize) : maxSize_m(maxSize) {}

    void push(int x)
    {
        if (stack_m.size() < maxSize_m)
            stack_m.emplace_back(x);
    }

    int pop()
    {
        if (stack_m.empty())
            return -1;

        int top = stack_m.back();
        stack_m.pop_back();
        return top;
    }

    void increment(int k, int val)
    {
        const int bound = min(k, (int)stack_m.size());
        for (int i = 0; i < bound; ++i)
        {
            stack_m[i] += val;
        }
    }

private:
    const int maxSize_m;
    vector<int> stack_m;
};