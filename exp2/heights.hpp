#include "Stack.hpp"
#define testConut 10
//using monotonic stack 
int maxArea(Vector<int> &heights)
{
    Stack<int> stk;
    int maxArea = 0;
    // heights.insert(0);
    for (int i = 0; i < heights.size(); ++i)
    {
        while (!stk.empty() && heights[stk.top()] > heights[i])
        {
            int h = heights[stk.pop()];
            // stk.pop();
            int w = stk.empty() ? i : i - stk.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        stk.push(i);
    }
    return maxArea;
}
void rand_test(int n)
{
    Vector<int> heights(n,n,0);
    for (int i = 0; i < n; i++)
        heights[i] = rand() % 105; // 生成0，104范围内的随机数
        //heights[i] = rand() % 10;
    int area = maxArea(heights);
    cout << "heights:[";
    for (int i = 0; i < n - 1; i++)
    {
        cout << heights[i] << ',';
    }
    cout << heights[n - 1] << ']' << endl;
    cout << area << endl;
}