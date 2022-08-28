#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
const int N=110;
int n;

int main()
{
    cin>>n;
    vector<int> st;
    while(n--){
        st.clear();//clear()消除元素不回收内存
        int a;
        scanf("%d",&a);
        for(int i=1;i<=a/i;i++)
        {
            if(a%i==0)
            {
                st.push_back(i);
                if(i!=a/i) st.push_back(a/i);
            }
        }
        sort(st.begin(),st.end());
        for(auto i=st.begin();i!=st.end();i++)
        {
            cout<<*i<<" ";
        }
        cout<<endl;
    }
    return  0;
}
    
    
                
                