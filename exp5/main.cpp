#include "Vector.cpp"
#include <random>
#define newline cout << endl;
#define SAMPLE_NUMBER 20
int random_num()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 20);
    return int(dis(gen));
}
void bubble_time(Vector<int> v1)
{
    clock_t start, end;
    double spendtime;
    // 冒泡排序
    start = clock();
    bubbleSort(v1, 0, v1.size());
    end = clock();
    spendtime = ((double)(end - start)); // CLOCKS_PER_SEC = 1000
    cout << "Bubble Sort took " << spendtime << " ms" << endl;
}
int main()
{
    // 排序效率(需要样本数量超过10000才有明显变化)
    Vector<int> bigcv(SAMPLE_NUMBER);
    for (int i = 0; i < SAMPLE_NUMBER; ++i)
    {
        int rc = random_num();
        bigcv.insert(rc);
    }
    // 顺序
    Vector<int> mcv = bigcv;
    bubbleSort(mcv, 0, mcv.size());
    cout << "The ordering efficiency of the order Vector is" << endl;
    print(mcv);
    bubble_time(mcv);
    newline;
    Vector<int> uncv1 = bigcv;
    uncv1.unsort();
    // 乱序
    Vector<int> ucv = uncv1;
    cout << "The ordering efficiency of the unsorted Vector is" << endl;
    bubble_time(ucv);
    newline;
    // 逆序
    Vector<int> recv(bigcv.size());
    Rank i = 0, j = mcv.size() - 1;
    while (i < mcv.size() && j > 0)
        recv[i++] = mcv[j--];
    cout << "The ordering efficiency of the reverse Vector is" << endl;
    bubble_time(recv);
    newline;
    return 0;
}
