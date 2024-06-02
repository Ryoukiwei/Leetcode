#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    MyQueue() {}

    void push(int x)
    {
        __new.push(x);
    }

    int pop()
    {
        migrateStack();
        int val = __old.top();
        __old.pop();

        return val;
    }

    int peek()
    {
        migrateStack();
        return __old.top();
    }

    bool empty()
    {
        return __old.empty() && __new.empty();
    }

private:
    stack<int> __old, __new;

    void migrateStack()
    {
        if (!__old.empty())
            return;

        while (!__new.empty())
        {
            __old.push(__new.top());
            __new.pop();
        }
    }
};