#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class stack
{
private:
    int top = -1;
    int size;
    vector<int> arr;

public:
    stack(int s)
    {
        arr.reserve(s);
        size = s;
    }

    void push(int val)
    {
        if (top == size - 1)
            return;
        else
            arr.push_back(val);
    }
    bool is_empty()
    {
        if (top == -1)
            return true;
        return false;
    }
    void pop()
    {
        if (top == -1)
        {
            throw runtime_error("Division by zero is not allowed.");
        }
        top--;
    }

    int top()
    {
        if (is_empty())
        {
            return -1;
        }
        return arr[top];
    }
    int get_size()
    {
        return size;
    }
};