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

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, vector<string>> lookup;
    int n = beginWord.size();
    unordered_map<string, int> visited;
    for(string word: wordList)
    {
        string s;
        for(int i = 0; i<n; i++)
        {
            s = word.substr(0,i);
            s += '*';
            s += word.substr(i+1);
            lookup[s].push_back(word);
        }
    }
    queue<pair<int, string>> q;
    q.push({1, beginWord});
    while(!q.empty())
    {
        int level = q.front().first;
        string curr = q.front().second;
        q.pop();
        string s;
        for(int i = 0; i<n; i++)
        {
            s = curr.substr(0,i);
            s += '*';
            s += curr.substr(i+1);
            for(string a: lookup[s])
            {
                if(a==endWord)
                    return level+1;
                if(visited.find(a)==visited.end())
                {
                    visited[a] = 1;
                    q.push({level+1, a});
                }
            }
        }
    }

    return 0;
}

void solve()
{
    string beginword, endword;
    cin>>beginword>>endword;
    input(n);
    string s;
    vector<string> wordList(n);
    rep(i, 0, n){
        cin>>s;
        wordList[i] = s;
    }
    cout<<ladderLength(beginword, endword, wordList);
    nl;
}

int main(){
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif
    int test_cases;
    cin >> test_cases;
    while(test_cases--)
    {
        solve();
    }
    return 0;
}
