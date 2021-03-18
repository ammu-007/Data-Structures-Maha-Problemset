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

long substrCount(int n, string s) {
    long result = 0;
    int arr[2][26];
    for(int i = 0; i<n; i++)
    {
        arr[0][i] = 0;
        arr[1][i] = 0;
    }
    for(int i = 1; i<=n; i++)
    {
        deb(i);
        deb(arr[0][s[i-1]-'a']);
        deb(arr[1][s[i-1]-'a']);
        // if(arr[0][s[i-1]-'a']==0 || i-arr[0][s[i-1]-'a']>2)
        // {
        //     deb(arr[0][s[i-1]-'a']);
        //     deb(arr[1][s[i-1]-'a']);
        //     arr[0][s[i-1]-'a'] = i;
        //     arr[1][s[i-1]-'a'] = 1;
        // }
        // else
        // {
        //     if(i-arr[0][s[i-1]-'a']==1)
        //     {
        //         arr[1][s[i-1]-'a']+=1;
        //         arr[0][s[i-1]-'a'] = i;
        //     }
        //     else if(i-arr[0][s[i-1]-'a']==2)
        //     {
        //         arr[1][s[i-1]-'a'] = 2;
        //         arr[0][s[i-1]-'a'] = i;
        //     }            
        // }
        // result+=arr[1][s[i-1]-'a'];
        // deb(result);
    }
    return result;
}

void solve()
{
    input(n);
    string s;
    cin>>s;   
    cout<<s;
    cout<<substrCount(n,s);
}

int main(){
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif
    int test_cases=1;
    // cin >> test_cases;
    while(test_cases--)
    {
        solve();
    }
    return 0;
}
