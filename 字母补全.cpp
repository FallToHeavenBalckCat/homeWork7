#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_set>
using namespace std;
const int N=50010;

int main()
{
    unordered_set<char> h;
    vector<char> s;
    
    string str;
    cin>>str;
    
    for(int i=25;i<str.size();i++)
    {
        h.clear();
        bool flag=true;
        for(int j=i-25;j<=i;j++)
        {
            //说明区间上有重复的元素,因为当前位置的元素不是？并且当前位置的元素已经出现过了，
            //说明这个元素必定是重复的
            if(str[j]!='?' && h.count(str[j]))
            {
                flag=false;
                break;
            }
            else 
            {
                h.insert(str[j]);
            }
        }
        //如果flag=true说明该区间上必定存在合理方案，把这个区间上的？替换掉之后
        //区间上的其他元素全部补上'A'就可以了
        if(flag)
        {
            s.clear();
            //遍历a-z的所有字母把没有出现过的字母加入到数组中
            for(char j='A';j<='Z';j++)
            {
                if(!h.count(j)) 
                {
                    s.push_back(j);
                }
            }
            //遍历区间上的元素将带有?的替换掉
            for(int j=i-25,k=0;j<=i;j++)
            {
                if(str[j]=='?')
                {
                    str[j]=s[k++];
                }
            }
            for(auto& c:str)
            {
                if(c=='?')
                    c='A';
            }
            cout<<str<<endl;
            return 0;
        }
    }
    puts("-1");
    return 0;
}