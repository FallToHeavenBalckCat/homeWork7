#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<cmath>
using namespace std;
const int N=110,mod=1e9+7;

typedef long long LL;
LL res=1;
unordered_map<int,int> h;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        for(int i=2;i<=x/i;i++)
        {
            while(x%i==0){
                x/=i;
                h[i]++;
            }
        }
        if(x>1) h[x]++;
    }
    
    for(auto prime:h) {
        int base=prime.first,index=prime.second;
        LL t=1;
        while(index--) t=(t*base+1)%mod;
        res=res*t%mod;
    }
    cout<<res<<endl;
    return 0;
}

