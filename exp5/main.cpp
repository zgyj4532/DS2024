#include "Vector.cpp"
#define newline cout << endl;
#define SAMPLE_NUMBER 10
int main()
{
    // 生成一个无序的复数向量
    Vector<int> cv;
    for (int i = 0; i < SAMPLE_NUMBER; ++i)
    {
        int rc = random()*2-1;
        cv.insert(rc);
    }
    newline;
    // 置乱
    Vector<int> uncv = cv;
    uncv.unsort();
    //唯一化
    Vector<int> dcv;
        for (int i = 0; i < 5; ++i)
    {
        int rc = random()*2-1;
        dcv.insert(rc);
        dcv.insert(rc);
    }
    cout << "The original int vector is :" << endl;
    print(dcv);
    dcv.uniquify();
    newline;
    cout << "And then uniquify int vector is :" << endl;
    print(dcv);
    newline;
   // 排序效率(需要样本数量超过10000才有明显变化)
    Vector<int> bigcv(10000);
    for (int i = 0; i < 10000; ++i)
    {
        int rc = random()*20-10;
        bigcv.insert(rc);
    }
    // 顺序
    Vector<int> mcv = bigcv;
    mergeSort(mcv, 0, mcv.size());
    cout << "The ordering efficiency of the order Vector is" << endl;
    test_time(mcv);
    newline;
    Vector<int> uncv1 = bigcv;
    uncv.unsort();
    // 乱序
    Vector<int> ucv = uncv1;
    cout << "The ordering efficiency of the unsorted Vector is" << endl;
    test_time(ucv);
    newline;
    // 逆序
    Vector<int> recv(mcv.size());
    Rank i = 0, j = mcv.size() - 1;
    while (i < mcv.size() && j>0)
        recv[i++] = mcv[j--];
    cout << "The ordering efficiency of the reverse Vector is" << endl;
    test_time(recv);
    newline;
    return 0;
}

