#include "Vector.cpp"
#include "List.cpp"
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
void merge_time(Vector<int> v2)
{
    clock_t start, end;
    double spendtime;
    // 冒泡排序
    start = clock();
    mergeSort(v2, 0, v2.size());
    end = clock();
    spendtime = ((double)(end - start));
    cout << "Merge Sort took " << spendtime << " ms" << endl;
}
void vec_to_list(Vector<int> v,List<int> &l)
{
    for(int i = 0;i<v.size();i++)
    {
        l.insertLast(v[i]);
        
    }
}
void printE(int& e) {
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
    // 冒泡排序
    cout << "BubbleSort" << endl;
    // 顺序
    Vector<int> mcv = bigcv;
    bubbleSort(mcv, 0, mcv.size());
    cout << "the order Vector is" << endl;
    bubble_time(mcv);
    newline;
    // 乱序
    Vector<int> uncv1 = bigcv;
    uncv1.unsort();
    Vector<int> ucv = uncv1;
    cout << "the unsorted Vector is" << endl;
    bubble_time(ucv);
    newline;
    // 逆序
    Vector<int> recv(bigcv.size());
    Rank i = 0, j = mcv.size() - 1;
    while (i < mcv.size() && j > 0)
        recv[i++] = mcv[j--];
    cout << "the reverse Vector is" << endl;
    bubble_time(recv);
    newline;
    // 归并排序
    // 顺序
    bubbleSort(mcv, 0, mcv.size());
    cout << "the order Vector is" << endl;
    merge_time(mcv);
    newline;
    // 乱序
    ucv.unsort();
    cout << "the unsorted Vector is" << endl;
    merge_time(ucv);
    newline;
    // 逆序
    i = 0, j = mcv.size() - 1;
    while (i < mcv.size() && j > 0)
        recv[i++] = mcv[j--];
    cout << "the reverse Vector is" << endl;    
    merge_time(recv);
    newline;
    //插入排序
    List<int> lis;
    vec_to_list(bigcv,lis);
    
    return 0;
}
