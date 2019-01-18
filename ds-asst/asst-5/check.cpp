#include <bits/stdc++.h>
using namespace std;

class A
{
private:
    int m_id;
    static int count;
public:
    A() {count++; m_id = count;}
    A(int id) { m_id = id; }
    // ~A() {cout<< "Destructor A "   <<m_id<<endl; }
};

int A::count = 0;

void f1()
{
    A* arr = new A[10];
    //delete operate only one constructor, and crash!
    delete[] arr;
    cout << arr << endl;
    //delete[] arr;
}

int main()
{
    f1();
    // system("PAUSE");
    return 0;
}
