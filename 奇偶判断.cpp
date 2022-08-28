#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int t=str.back()-'0';
    if(t%2==0)
        cout<<0<<endl;
    else 
        cout<<1<<endl;
    return 0;
}