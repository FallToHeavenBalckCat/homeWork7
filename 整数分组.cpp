#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 110;

int n;
//开一个二位数组，p[x]表示集合内数字为x的对应的下标数组
vector<int> p[N];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i ++ )
    {
        int x;
        cin >> x;
        //把数字为x的对应的所有下把i存下
        p[x].push_back(i);
    }

    int cnt = 0;//保存出现次数为1的数字个数
    for (int i = 0; i < N; i ++ )//si<100
        if (p[i].size() == 1)
            cnt ++ ;

    string res(n, 'A');
    for (int i = 0, k = 0; i < N; i ++ )
        if (p[i].size() == 1)
        {
            k ++ ;
            if (k <= cnt / 2) res[p[i][0]] = 'A';
            else res[p[i][0]] = 'B';
        }

    bool flag = true;
    if (cnt % 2)
    {
        flag = false;
        for (int i = 0; i < N; i ++ )
            if (p[i].size() > 2)
            {
                flag = true;
                res[p[i][0]] = 'A';
                for (int j = 1; j < p[i].size(); j ++ )
                    res[p[i][j]] = 'B';
                break;
            }
    }

    if (flag)
    {
        puts("YES");
        cout << res << endl;
    }
    else puts("NO");

    return 0;
}

