#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100010;

int gcb(int a,int b){
    return b?gcb(b,a%b):a;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        cout<<gcb(a,b)<<endl;
    }
    return 0;
}