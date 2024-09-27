#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo
{
public:
    MyCalendarTwo() {}

    bool book(int start, int end)
    {
        for (const auto &overlap : overlaps)
        {
            if (start < overlap.second && end > overlap.first)
                return false;
        }

        for (const auto &event : events)
        {
            if (start < event.second && end > event.first)
                overlaps.emplace_back(max(start, event.first), min(end, event.second));
        }

        events.emplace_back(start, end);
        return true;
    }

private:
    vector<pair<int, int>> events;
    vector<pair<int, int>> overlaps;
};