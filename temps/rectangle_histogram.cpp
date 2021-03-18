#include <iostream>
#include <bits/stdc++.h>
#define deb(x) cout<<#x<<": "<<x<<endl
#define print(any)      for(auto i:any) cout<<i<<" "; nl;
#define nl              cout<<'\n'
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<pair<int, int>>stk;
    heights.push_back(-1);
    int n = heights.size();
    int pos_l[n-1];
    int pos_r[n-1];
    for (int i = 0; i < n; i++)
    {
        if(stk.empty() || stk.top().first < heights[i])
            stk.push({heights[i], i});
        else
        {
            while(!stk.empty() && stk.top().first > heights[i])
            {
                pos_l[stk.top().second] = i;
                stk.pop();
            }
            stk.push({heights[i], i});
        }
            
    }
    n--;
    for (int i = n-1; i>=0; i--)
    {
        if(stk.empty() || stk.top().first < heights[i])
            stk.push({heights[i], i});
        else
        {
            while(!stk.empty() && stk.top().first > heights[i])
            {
                pos_r[stk.top().second] = i;
                stk.pop();
            }
            stk.push({heights[i], i});
        }
            
    }
    while(!stk.empty())
    {
        pos_r[stk.top().second] = -1;
        stk.pop();
    }
    print(pos_r);
    int max_area = 0;
    for(int i = 0; i<n; i++)
    {
        max_area = max(max_area, ((pos_l[i]-i)*heights[i])+((i - pos_r[i] - 1)*heights[i]));
    }
    return max_area;
}

int main()
{
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif
    vector<int> heights;
    int x;  
    while(cin>>x){
        heights.push_back(x);
    }   
    cout<<largestRectangleArea(heights);
    cout << endl;
}