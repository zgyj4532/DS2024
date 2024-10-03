#include <iostream>
#include "Vector.cpp"
#include "Complex.cpp"
using namespace std;
#define newline cout<<endl; 

int main()
{
    // 生成一个无序的复数向量
    Vector<Complex> cv;
    for (int i = 0; i < 10; ++i)
    {
        Complex rc = randomcomp(-10.0, 10.0);
        cv.insert(rc);
    }
    cout << "The original complex vector is :" << endl;
    for (int i = 0; i < cv.size(); i++)
    {
        cv[i].print();
    }
    cout << endl;
    // 置乱
    Vector<Complex> uncv =cv;
    uncv.unsort();
    cout << "And then unsort complex vector is :" << endl;
    for (int i = 0; i < uncv.size(); i++)
    {
        uncv[i].print();
    }
    
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
    for (int i = 0; i < icv.size(); i++)
    {
        icv[i].print();
    }
    //删除
    Vector<Complex> rcv = icv ;
    rcv.remove(4,9);
    newline;
    cout << "And then remove complex vector is :" << endl;
    for (int i = 0; i < rcv.size(); i++)
    {
        rcv[i].print();
    }
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
    dcv.deduplicate();
    newline;
    cout << "And then deduplicate complex vector is :" << endl;
    for (int i = 0; i < dcv.size(); i++)
    {
        dcv[i].print();
    }
    return 0;
}
