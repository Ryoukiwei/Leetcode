#include <bits/stdc++.h>
using namespace std;

class MyCalendar
{
public:
    MyCalendar() {}

    bool book(int start, int end)
    {
        auto it = events.upper_bound(start);
        if (it == events.end() || it->second >= end)
        {
            events[end] = start;
            return true;
        }
        return false;
    }

private:
    map<int, int> events;
};
