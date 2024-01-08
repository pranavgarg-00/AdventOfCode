#include<iostream>
#include<typeinfo>
using namespace std;
int main()
{
    string s = "1011";
    cout<<typeid(s[1]).name()<<endl;
    cout<<s[0]<<endl<<s[1];
    return 0;
} 