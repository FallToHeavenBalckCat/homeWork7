#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+10;

int prime[N];
bool st[N];

int main()
{
    int n;
    cin>>n;
    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
            prime[cnt++]=i;
            for(int j=i;j<=n;j+=i)
            {
                st[j]=true;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}