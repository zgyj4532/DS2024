#include "Stack.hpp"
#define testConut 10
//使用动态规划
int maxArea(Vector<int> &heights)
{

    int n = heights.size();
    if(n==0) return 0;
    //example 2,1,5,6,2,3
    Vector<int> leftmin(n);//height中位置i左侧最近的元素小于该柱子的位置
    Vector<int> rightmin(n);//height中位置i右侧最近的元素小于该柱子的位置

    leftmin[0] = -1;
    for(int i=1;i<n;++i){
        int t=i-1;
        while (t>= 0 && heights[t] >= heights[i])
        {
            t =leftmin[t];
        }
        leftmin[i] = t;
        //cout<<leftmin[i-1]<<endl;
    }//循环结束后leftmin值为 -1,-1，1，2，1，4
        rightmin[n-1] = n;
    for(int i=n-2;i>=0;--i){
        int t=i+1;
        while (t<n && heights[t] >= heights[i])
        {
            t =rightmin[t];
        }
        rightmin[i] = t;
        // cout<<rightmin[i]<<endl;
    }//循环结束后rightmin值为1,6,4,4,6,6 (6等效于leftmin中的-1为找不到)

    int maxArea = 0;
    for(int i=0;i<n;++i)
    {
        int h=heights[i];
        int w=rightmin[i]-leftmin[i]-1;
        maxArea = max(maxArea,h*w);
    }

    return maxArea;
}
void rand_test(int n)
{
    // int a[n]={2,1,5,6,2,3};
    Vector<int> heights(n,n,0);
    
    cout << "heights:[";
    for (int i = 0; i < n - 1; i++)
    {
        heights[i] = rand() % 104;// 生成0，104范围内的随机数
        cout << heights[i] << ',';
    }
    int area = maxArea(heights);
    cout << heights[n - 1] << ']' << endl;
    cout << area << endl;
}