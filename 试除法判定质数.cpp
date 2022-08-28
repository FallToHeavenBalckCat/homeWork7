#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=110;
int n;

bool prime(int a)
{
    if (a<2) return false;
    for(int i=2;i<=a/i;i++)
    {
        if(a%i==0) return false;
    }
    return true;
}
    
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int a=0;
        scanf("%d",&a);
        if(prime(a)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}