#include "Complex.cpp"
#define SAMPLE_NUMBER 10
#define newline cout << endl;

int main()
{
    // 生成一个无序的复数向量
    Vector<Complex> cv;
    for (int i = 0; i < SAMPLE_NUMBER; ++i)
    {
        Complex rc = randomcomp(-10.0, 10.0);
        cv.insert(rc);
    }
    cout << "The original complex vector is :" << endl;
    printVector(cv);
    newline;
    // 置乱
    Vector<Complex> uncv = cv;
    uncv.unsort();
    cout << "And then unsort complex vector is :" << endl;
    printVector(uncv);

    // 查找
    Vector<Complex> scv = cv;
    for (int i = 0; i < scv.size(); i++)
    {
        scv[i].same();//实现实部与虚部均相同
    }
    Complex aim_elem = scv[2];
    newline;
    cout << "The element to look for is:";
    aim_elem.print();
    newline;
    cout<<"Targer is at index:"<<scv.find(aim_elem)<<endl;
    //插入
    Vector<Complex> icv = cv;
    Complex insert_elem = Complex(1.14,5.14);
    cout << "The element to insert index 4 is:";
    insert_elem.print();
    newline;
    icv.insert(4,insert_elem);
    cout << "And then insert complex vector is :" << endl;
    printVector(icv);
    //删除
    Vector<Complex> rcv = icv ;
    rcv.remove(4,9);
    newline;
    cout << "And then remove complex vector is :" << endl;
    printVector(rcv);
    newline;
    //唯一化
    Vector<Complex> dcv;
        for (int i = 0; i < 5; ++i)
    {
        Complex rc = randomcomp(-10.0, 10.0);
        dcv.insert(rc);
        dcv.insert(rc);
    }
    cout << "The original complex vector is :" << endl;
    for (int i = 0; i < dcv.size(); i++)
    {
        dcv[i].print();
    }
    dcv.uniquify();
    newline;
    cout << "And then uniquify complex vector is :" << endl;
    printVector(dcv);
    newline;
    // 排序效率(需要样本数量超过10000才有明显变化)
    // 顺序
    Vector<Complex> mcv = cv;
    mergeSort(mcv, 0, mcv.size());
    cout << "The ordering efficiency of the order Vector is" << endl;
    test_time(mcv);
    newline;
    // 乱序
    Vector<Complex> ucv = uncv;
    cout << "The ordering efficiency of the unsorted Vector is" << endl;
    test_time(ucv);
    newline;
    // 逆序
    Vector<Complex> recv;
    Rank i = 0, j = mcv.size() - 1;
    while (i < mcv.size())
        recv[i++] = mcv[j--];
    cout << "The ordering efficiency of the reverse Vector is" << endl;
    test_time(recv);
    newline;
    return 0;
}

