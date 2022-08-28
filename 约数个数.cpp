#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int N=110,mod=1e9+7;

unordered_map<int,int> h;
typedef long long LL;
LL res=1;

int main(){
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        scanf("%d",&x);
        for(int i=2;i<=x/i;i++)
        {
            while(x%i==0) 
            {
                x/=i;
                h[i]++;
            }
        }
        if(x>1) h[x]++;
    }
    
    for(auto  prime:h) res=res*(prime.second+1)%mod;
    cout<<res<<endl;
    return 0;
}