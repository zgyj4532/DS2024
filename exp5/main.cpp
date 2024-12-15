#include "time.hpp"
#define SAMPLE_NUMBER 30
int main()
{
    // 排序效率(需要样本数量超过10000才有明显变化)
    Vector<int> bigcv(SAMPLE_NUMBER);
    for (int i = 0; i < SAMPLE_NUMBER; ++i)
    {
        int rc = tis::random_num();
        bigcv.insert(rc);
    }
    cout << "the base vector is:" << endl;
    bigcv.traverse(tis::printE);//输出原数组
    newline;
    // 冒泡排序
    tis::sort_time(bigcv, &Vector<int>::bubbleSort,"Bubble Sort took ");
    // 归并排序
    tis::sort_time(bigcv, &Vector<int>::mergeSort,"Merge Sort took ");
    // 插入排序
    tis::sort_time(bigcv, &Vector<int>::insertionSort,"Insertion Sort took ");
    // 选择排序
    tis::sort_time(bigcv, &Vector<int>::selectionSort,"Selection Sort took ");
    // 快速排序
    tis::sort_time(bigcv, &Vector<int>::quickSort,"quick Sort took ");
    return 0;
}
