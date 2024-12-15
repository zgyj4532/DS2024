#include "Vector.cpp"
#include <random>
#define newline cout << endl
namespace tis
{
    int random_num()
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 20);
        return int(dis(gen));
    }
    template <typename T>
    void way_time(Vector<T> &v, void (Vector<T>::*sort_fn)(Rank, Rank), const string &output_str)
    {
        clock_t start, end;
        double spendtime;

        start = clock();

        (v.*sort_fn)(0, v.size());

        end = clock();

        spendtime = ((double)(end - start));

        cout << output_str << spendtime << " ms" << endl;
    }

    template <typename T>
    void sort_time(Vector<T> &bigcv,  void (Vector<T>::*sort_fn)(Rank, Rank), const string &output_str)
    {
        // 顺序排序
        Vector<int> mcv = bigcv;
        cout << "the order Vector:" << endl;
        (mcv.*sort_fn)(0, mcv.size());      
        way_time(mcv, sort_fn, output_str); 
        newline;

        // 乱序排序
        Vector<int>
            uncv1 = bigcv;
        cout << "the unorder Vector:" << endl;
        uncv1.unsort();
        Vector<int> ucv = uncv1;
        way_time(uncv1, sort_fn, output_str);
        newline;

        // 逆序排序
        Vector<int>
            recv(bigcv.size()); // 创建一个新的 Vector 用来存放逆序数据
        Rank i = 0, j = mcv.size() - 1;
        while (i < mcv.size() && j >= 0)
            recv[i++] = mcv[j--];
        cout << "the reverse Vector:" << endl;
        way_time(recv, sort_fn, output_str);
        newline;
    }
    
}