#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<": "<<x<<endl
#define scan(arr, n)      vector<int>arr(n); for(int i=0;i<n;i++) cin>>arr[i];
#define inputs(n, m) int n,m;cin>>n>>m
#define input(n) int n;cin>>n
#define print(any)      for(auto i:any) cout<<i<<" "; nl;
#define nl              cout<<'\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int,int>
#define piii pair<pair<int,int>,int>
#define all(v) (v).begin(), (v).end()
#define sz(x) (int)x.size()
#define rep(i,a,b) for (int i = a; i < b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)

const int N = int(1e5 + 3);
#define modulo 1000000007


void solve()
{
    inputs(n, q);
    vector<int>arr(n);
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    set<int>s;
    s.insert(1);
    for(int i=1; i<n; i++)
    {
        if(arr[i]%arr[i-1]!=0)
            s.insert(i+1);
    }
    for(int i = 0; i<q; i++)
    {
        input(x);
        if(x==1)
        {
            inputs(idx, rpl);
            idx--;
            if(idx-1>=0)
            {  
                if(rpl%arr[idx-1]!=0)
                    s.insert(idx+1);
                else{
                    if(s.find(idx+1)!=s.end())
                        s.erase(idx+1);
                }
            }
            if(idx+1<n)
            {
                if(arr[idx+1]%rpl!=0)
                    s.insert(idx+2);
                else{
                    if(s.find(idx+2)!=s.end())
                        s.erase(idx+2);
                }
                
            }
            arr[idx] = rpl;
        }
        else
        {
            input(id);
            set<int> :: iterator itr;
            itr = s.upper_bound(id);
            itr--;
            cout<<*itr<<"\n";
        }
        // print(s);
    }
}

int main(){
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif
    solve();
    return 0;
}
