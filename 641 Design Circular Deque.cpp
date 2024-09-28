#include <vector>
using namespace std;

class MyCircularDeque
{
public:
    MyCircularDeque(int k) : k(k), dq(k), front(0), rear(k - 1), size(0) {}

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        front = (--front + k) % k;
        dq[front] = value;
        ++size;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        rear = ++rear % k;
        dq[rear] = value;
        ++size;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        front = ++front % k;
        --size;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        rear = (--rear + k) % k;
        --size;
        return true;
    }

    int getFront()
    {
        return isEmpty() ? -1 : dq[front];
    }

    int getRear()
    {
        return isEmpty() ? -1 : dq[rear];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == k;
    }

private:
    const int k;
    vector<int> dq;
    int front;
    int rear;
    size_t size;
};