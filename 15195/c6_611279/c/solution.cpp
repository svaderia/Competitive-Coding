#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define int lli
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD   = 1e9 + 7;
const double PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const lli INF   = 1e18;

#define fastio            ios_base::sync_with_stdio(false);cin.tie(0)
#define sz(a) int((a).size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define f first
#define s second
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define endl "\n"
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

void solve(){
    int nn = 100;

    map<int, int> where;
    rep(i, nn){
        where[i] = i;
    }

    int n;
    cin >> n;

    rep(i, n){
        int x, y;
        cin >> x >> y;
        x--; y--;
        where[min(x, y)] = max(x, y);
    }

    int m;
    cin >> m;

    rep(i, m){
        int x, y;
        cin >> x >> y;
        x--; y--;
        where[max(x, y)] = min(x, y);
    }

    int s = 0;

    vi visited(nn, -1);

    queue<int> pending;
    pending.push(s);
    visited[s] = 0;

    while(!pending.empty()){
        int root = pending.front();
        pending.pop();
        repA(i, 1, 6){
            int child = root + i;
            /* cout << root << spc << child << spc << visited[root] << spc  << where[child] << endl; */
            if(child >= 100) continue;

            child = where[child];

            if(visited[child] == -1){
                visited[child] = visited[root] + 1;
                /* cout << child << spc << visited[child] << endl; */
                pending.push(child);
            }
        }
    }

    cout << visited[nn - 1] << endl;

}

signed main(){
    fastio;

    int T;
    cin >> T;

    repA(tc, 1, T){
        solve();
    }

    return 0;
}
