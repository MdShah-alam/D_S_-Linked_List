#include<bits/stdc++.h>
using namespace std;

template<typename T1,typename T2>
T2 sum(T1 a,T1 b)
{
    T2 s=(a+b)*2.11;
    return s;
}

int main()
{
    int a=10,b=20;
    double s=sum<int,double>(a,b);
    cout<<s<<endl;

}
