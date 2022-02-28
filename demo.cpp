/* ************************************************************************
> File Name:     demo.cpp
> Author:        程序员Phil
> 微信公众号:    程序员Phil
> Created Time:  Sat 26 Feb 2022 11:08:18 PM CST
> Description:   
 ************************************************************************/


#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
static unordered_map<int, int> costs = {
    {1, 2}, {2, 5}, {3, 5}, {4, 4},
    {5, 5}, {6, 6}, {7, 3}, {8, 7}, {9, 6},
};

static unordered_map<int, int> costss = {
    {1, 100}, {2, 1}, {3, 1}, {4, 1},
    {5, 1}, {6, 1}, {7, 1}, {8, 1}, {9, 1},
};
int main()
{
    int m;
    cin>>m;
    while(m--)
    {
        int n;
        cin>>n;
        map<int,int>m;
        for(int i = 0;i<n;++i)
        {
            int temp;
            cin>>temp;
            m[temp]++;
        }
        int count = 0;
        map<int,int>::iterator iter;
        for(iter = m.begin();iter!=m.end();++iter)
        {
              if(iter->second == 1)
              {
                  cout<<iter->first<<endl;
                  break;
              }
        }
        if(iter == m.end()) cout<<"-1"<<endl;
    }
    return 0;
}
