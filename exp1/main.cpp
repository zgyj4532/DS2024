#include <iostream>
#include "Vector.cpp"
#include "Complex.cpp"
using namespace std;

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
    for (int i = 0; i < 10; i++)
    {
        cv[i].print();
    }
    cout << endl;
    // 置乱
    Vector<Complex> uncv =cv;
    uncv.unsort();
    cout << "And then unsort complex vector is :" << endl;
    for (int i = 0; i < 10; i++)
    {
        uncv[i].print();
    }
    // 查找
    Vector<Complex> scv = cv;
    for (int i = 0; i < 10; i++)
    {
        scv[i].same();//实现实部与虚部均相同
    }
    Complex aim_elem = scv[2];
    cout << "The element to look for is;"<<endl;
    aim_elem.print();
    cout<<endl;
    scv.search(aim_elem);

    
    
    return 0;
}
