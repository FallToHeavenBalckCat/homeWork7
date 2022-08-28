#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=110;
int n;

int main()
{
    cin>>n;
    while(n--)
    {
        int a;
        scanf("%d",&a);
        for(int i=2;i<=a/i;i++)
        {
            if(a%i==0) 
            {
                int s=0;
                while(a%i==0)
                {
                    a/=i;
                    s++;
                }
                cout<<i<<" "<<s<<endl;
            }
        }
        if(a>1) cout<<a<<" "<<1<<endl;
        cout<<endl;
    }
    return 0;
}
