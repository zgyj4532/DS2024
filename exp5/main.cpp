#include "Vector.cpp"
#include <random>
#define newline cout << endl
#define SAMPLE_NUMBER 20
int random_num()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 20);
    return int(dis(gen));
}
void sort_time(Vector<int> &bigcv, void (*way_time)(Vector<int> &))
{
    // 顺序排序
    Vector<int> mcv = bigcv;             // 复制原始数据
    cout << "the order Vector:" << endl; // 顺序
    mcv.bubbleSort(0, mcv.size());      // 使用冒泡排序
    way_time(mcv);                       // 输出排序时间
    newline;                             // 换行

    // 乱序排序
    Vector<int>
        uncv1 = bigcv;                     // 复制原始数据
    cout << "the unorder Vector:" << endl; // 逆序
    uncv1.unsort();                        // 将向量乱序
    Vector<int> ucv = uncv1;               // 复制乱序后的数据
    way_time(ucv);                         // 输出排序时间
    newline;                               // 换行

    // 逆序排序
    Vector<int>
        recv(bigcv.size()); // 创建一个新的 Vector 用来存放逆序数据
    Rank i = 0, j = mcv.size() - 1;
    while (i < mcv.size() && j >= 0)       // 逆序填充数据
        recv[i++] = mcv[j--];              // 从尾部复制到头部
    cout << "the reverse Vector:" << endl; // 倒序
    way_time(recv);                        // 输出排序时间
    newline;                               // 换行
}

void bubble_time(Vector<int> &v1)
{
    clock_t start, end;
    double spendtime;
    start = clock();
    v1.bubbleSort(0, v1.size());
    end = clock();
    spendtime = ((double)(end - start)); 
    cout << "Bubble Sort took " << spendtime << " ms" << endl;
}
void merge_time(Vector<int> &v2)
{
    clock_t start, end;
    double spendtime;
    start = clock();
    mergeSort(v2, 0, v2.size());
    end = clock();
    spendtime = ((double)(end - start));
    cout << "Merge Sort took " << spendtime << " ms" << endl;
}
void insert_time(Vector<int> &v3)
{
    clock_t start, end;
    double spendtime;
    start = clock();
    v3.insertionSort(0, v3.size());
    end = clock();
    spendtime = ((double)(end - start));
    cout << "insertion Sort took " << spendtime << " ms" << endl;
}
void select_time(Vector<int> &v4)
{
    clock_t start, end;
    double spendtime;
    start = clock();
    v4.selectionSort(0, v4.size());
    end = clock();
    spendtime = ((double)(end - start));
    cout << "selection Sort took " << spendtime << " ms" << endl;
}
void printE(int &e)
{
    cout << e << " ";
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
    cout << "the base vector is:" << endl;
    bigcv.traverse(printE);
    newline;
    // 冒泡排序
    sort_time(bigcv, bubble_time);
    // 归并排序
    sort_time(bigcv, merge_time);
    // 插入排序
    sort_time(bigcv, insert_time);
    // 选择排序
    sort_time(bigcv, select_time);
    return 0;
}
