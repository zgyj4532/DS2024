#include "Complex.hpp"
#define newline cout << endl;
#define SAMPLE_NUMBER 10
int main()
{
    // 生成一个无序的复数向量
    Vector<Complex> cv;
    for (int i = 0; i < SAMPLE_NUMBER; ++i)
    {
        Complex rc = randomcomp(-10.0, 10.0);
        cv.insert(rc);
    }
    newline;
    // 置乱
    Vector<Complex> uncv = cv;
    uncv.unsort();
    printVector(uncv);
    //唯一化
    Vector<Complex> dcv;
        for (int i = 0; i < 5; ++i)
    {
        Complex rc = randomcomp(-10.0, 10.0);
        dcv.insert(rc);
        dcv.insert(rc);
    }
    cout << "The original complex vector is :" << endl;
    printVector(dcv);
    dcv.uniquify();
    newline;
    cout << "And then uniquify complex vector is :" << endl;
    printVector(dcv);
    newline;
   // 排序效率(需要样本数量超过10000才有明显变化)
    Vector<Complex> bigcv(10000);
    for (int i = 0; i < 10000; ++i)
    {
        Complex rc = randomcomp(-10.0, 10.0);
        bigcv.insert(rc);
    }
    // 顺序
    Vector<Complex> mcv = bigcv;
    mergeSort(mcv, 0, mcv.size());
    cout << "The ordering efficiency of the order Vector is" << endl;
    test_time(mcv);
    newline;
    Vector<Complex> uncv1 = bigcv;
    uncv.unsort();
    // 乱序
    Vector<Complex> ucv = uncv1;
    cout << "The ordering efficiency of the unsorted Vector is" << endl;
    test_time(ucv);
    newline;
    // 逆序
    Vector<Complex> recv(mcv.size());
    Rank i = 0, j = mcv.size() - 1;
    while (i < mcv.size() && j>0)
        recv[i++] = mcv[j--];
    cout << "The ordering efficiency of the reverse Vector is" << endl;
    test_time(recv);
    newline;
    return 0;
}

