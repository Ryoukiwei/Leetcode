#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<ClassRatio> maxHeap;

        for (auto &cl : classes)
        {
            maxHeap.emplace(cl[0], cl[1]);
        }

        while (extraStudents--)
        {
            auto topClass = maxHeap.top();
            maxHeap.pop();
            topClass.addStudent();
            maxHeap.push(topClass);
        }

        double ans = 0;
        while (!maxHeap.empty())
        {
            auto topClass = maxHeap.top();
            maxHeap.pop();
            ans += ratio(topClass.passStdnt, topClass.totalStdnt);
        }

        return ans / classes.size();
    }

private:
    static double ratio(int a, int b) noexcept
    {
        return static_cast<double>(a) / b;
    }

    struct ClassRatio
    {
        int passStdnt;
        int totalStdnt;

        ClassRatio(int pass, int total) noexcept : passStdnt(pass), totalStdnt(total) {}

        double impact() const noexcept
        {
            return ratio(passStdnt + 1, totalStdnt + 1) - ratio(passStdnt, totalStdnt);
        }

        void addStudent() noexcept
        {
            ++passStdnt;
            ++totalStdnt;
        }

        bool operator<(const ClassRatio &other) const noexcept
        {
            return impact() < other.impact();
        }
    };
};