#include<iostream>
using namespace std;
class loc
{
    int log,lat;
    public: loc() {}
            loc(int lg,int lt)
            {
                log=lg;
                lat=lt;
            }
            void show()
            {
                cout<<log<<" ";
                cout<<lat<<"\n";
            }
            loc operator+(loc);
            loc operator-(loc);
            loc operator=(loc);
            loc operator++();
            loc operator++(int);
            loc operator+=(loc);
};
loc loc::operator+=(loc op)
{
    log=op.log+log;
    lat=op.lat+lat;
    return *this;
}
loc loc::operator+(loc op)
{
    loc t;
    t.log=op.log+log;
    t.lat=op.lat+lat;
    return t;
}
loc loc::operator-(loc op)
{
    loc t;
    t.log=op.log-log;
    t.lat=op.lat-lat;
    return t;
}
loc loc::operator=(loc op)
{
    log=op.log;
    lat=op.lat;
    return *this;
}
loc loc::operator++()
{
    cout<<"In prefix ++\n";
    log++;
    lat++;
    return *this;
}
loc loc::operator++(int x)
{
    cout<<"In postfix ++\n";
    loc t=(*this);
    log++;
    lat++;
    return t;
}
int main()
{
    loc o1(10,20),o2(5,30),o3(90,90);
    cout<<"o1 value ",o1.show();
    cout<<"o2 value ",o2.show();
    ++o1;
    cout<<"o1 value ",o1.show();
    o2=++o1;
    cout<<"o1 value ",o1.show();
    cout<<"o2 value ",o2.show();
    cout<<"Multiple assignment\n";
    o1=o2=o3;
    cout<<"o1 value ",o1.show();
    o2=o1++;
    cout<<"o1 value ",o1.show();
    cout<<"o2 value ",o2.show();
    cout<<"calling += operator fuss\n";
    o3+=o1;
    cout<<"o1 value ",o1.show();
    cout<<"o3 value ",o3.show();
    return 0;
}